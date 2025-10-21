#include "../include/library.h"

bool islem_mutlak(vector<vector<int>> &M, vector<string> &satirEtiket, vector<string> &sutunEtiket, set<string> &pi_kumesi)
{
    if (M.empty() || M[0].empty())
        return false;

    int mutlak_satir_indeksi = -1;

    for (size_t j = 0; j < M[0].size(); ++j)
    {
        int bir_sayisi = 0;
        int temp_satir_indeksi = -1;
        for (size_t i = 0; i < M.size(); ++i)
        {
            if (M[i][j] == 1)
            {
                bir_sayisi++;
                temp_satir_indeksi = i;
            }
        }

        if (bir_sayisi == 1)
        {
            mutlak_satir_indeksi = temp_satir_indeksi;
            break;
        }
    }

    if (mutlak_satir_indeksi != -1)
    {
        pi_kumesi.insert(satirEtiket[mutlak_satir_indeksi]);

        vector<bool> silinecek_sutunlar(M[0].size(), false);
        for (size_t j = 0; j < M[0].size(); ++j)
        {
            if (M[mutlak_satir_indeksi][j] == 1)
            {
                silinecek_sutunlar[j] = true;
            }
        }

        vector<vector<int>> yeni_M;
        vector<string> yeni_satirEtiket;
        for (size_t i = 0; i < M.size(); i++)
        {
            if (i == mutlak_satir_indeksi)
                continue;
            yeni_satirEtiket.push_back(satirEtiket[i]);
            vector<int> yeni_satir;
            for (size_t j = 0; j < M[0].size(); j++)
            {
                if (!silinecek_sutunlar[j])
                {
                    yeni_satir.push_back(M[i][j]);
                }
            }
            yeni_M.push_back(yeni_satir);
        }

        vector<string> yeni_sutunEtiket;
        for (size_t j = 0; j < sutunEtiket.size(); ++j)
        {
            if (!silinecek_sutunlar[j])
            {
                yeni_sutunEtiket.push_back(sutunEtiket[j]);
            }
        }

        M = yeni_M;
        satirEtiket = yeni_satirEtiket;
        sutunEtiket = yeni_sutunEtiket;

        return true;
    }

    return false;
}

void islem_sezgisel_silme(vector<vector<int>> &M, vector<string> &satirEtiket)
{
    if (M.empty())
        return;

    int en_dusuk_agirlik = -1;
    int silinecek_satir_indeksi = -1;

    for (size_t i = 0; i < M.size(); ++i)
    {
        int agirlik = 0;
        for (int val : M[i])
        {
            if (val == 1)
                agirlik++;
        }

        if (silinecek_satir_indeksi == -1 || agirlik < en_dusuk_agirlik)
        {
            en_dusuk_agirlik = agirlik;
            silinecek_satir_indeksi = i;
        }
    }

    if (silinecek_satir_indeksi != -1)
    {
        vector<vector<int>> yeni_M;
        vector<string> yeni_satirEtiket;
        for (size_t i = 0; i < M.size(); ++i)
        {
            if (i == (size_t)silinecek_satir_indeksi)
                continue;
            yeni_M.push_back(M[i]);
            yeni_satirEtiket.push_back(satirEtiket[i]);
        }
        M = yeni_M;
        satirEtiket = yeni_satirEtiket;
    }
}

void sadeles_satir(vector<vector<int>> &M, vector<string> &satirEtiket)
{
    if (M.empty())
        return;

    int satir = M.size();
    int sutun = M[0].size();
    vector<bool> aktif(satir, true);

    for (int i = 0; i < satir; i++)
    {
        for (int k = i + 1; k < satir; k++)
        {
            bool i_kapsar_k = true;
            bool k_kapsar_i = true;

            for (int j = 0; j < sutun; j++)
            {
                if (M[i][j] == 1 && M[k][j] == 0)
                    k_kapsar_i = false;
                if (M[k][j] == 1 && M[i][j] == 0)
                    i_kapsar_k = false;
            }

            if (i_kapsar_k && !k_kapsar_i)
                aktif[k] = false;
            else if (k_kapsar_i && !i_kapsar_k)
                aktif[i] = false;
        }
    }

    vector<vector<int>> yeni;
    vector<string> yeniEtiket;
    for (int i = 0; i < satir; i++)
    {
        if (aktif[i])
        {
            yeni.push_back(M[i]);
            yeniEtiket.push_back(satirEtiket[i]);
        }
    }

    M = yeni;
    satirEtiket = yeniEtiket;
}

void sadeles_sutun(vector<vector<int>> &M, vector<string> &sutunEtiket)
{
    if (M.empty() || M[0].empty())
        return;

    int satir = M.size();
    int sutun = M[0].size();
    vector<bool> aktif(sutun, true);

    for (int i = 0; i < sutun; i++)
    {
        for (int k = i + 1; k < sutun; k++)
        {
            bool ayni = true;
            bool i_kapsar_k = true;
            bool k_kapsar_i = true;

            for (int j = 0; j < satir; j++)
            {
                if (M[j][i] != M[j][k])
                    ayni = false;

                if (M[j][i] == 1 && M[j][k] == 0)
                    k_kapsar_i = false;
                if (M[j][k] == 1 && M[j][i] == 0)
                    i_kapsar_k = false;
            }

            if (ayni)
            {
                aktif[k] = false;
                continue;
            }

            if (i_kapsar_k && !k_kapsar_i)
                aktif[k] = false;
            else if (k_kapsar_i && !i_kapsar_k)
                aktif[i] = false;
        }
    }

    vector<vector<int>> yeni;
    for (int i = 0; i < satir; i++)
    {
        vector<int> yeniSat;
        for (int j = 0; j < sutun; j++)
            if (aktif[j])
                yeniSat.push_back(M[i][j]);
        yeni.push_back(yeniSat);
    }

    vector<string> yeniEtiket;
    for (int j = 0; j < sutun; j++)
        if (aktif[j])
            yeniEtiket.push_back(sutunEtiket[j]);

    M = yeni;
    sutunEtiket = yeniEtiket;
}
