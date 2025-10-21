#include "../include/library.h"

int main()
{
    vector<vector<int>> matrix = generateRandomMatrix();

    vector<string> satirEtiket;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        satirEtiket.push_back("A" + to_string(i));
    }

    vector<string> sutunEtiket;
    if (!matrix.empty() && !matrix[0].empty())
    {
        for (size_t i = 0; i < matrix[0].size(); ++i)
        {
            sutunEtiket.push_back("S" + to_string(i + 1));
        }
    }
    set<string> pi_kumesi;

    cout << "Baslangic matrisi:" << endl;
    yazdir(matrix, satirEtiket, sutunEtiket);

    int adim = 1;
    while (!matrix.empty() && (matrix.empty() ? false : !matrix[0].empty()))
    {
        cout << "\n--- Adim " << adim++ << " ---" << endl;

        if (islem_mutlak(matrix, satirEtiket, sutunEtiket, pi_kumesi))
        {
            cout << "Mutlak satir bulundu ve islendi." << endl;
            cout << "Guncel Pi Kumesi: { ";
            for (const auto &item : pi_kumesi)
            {
                cout << item << " ";
            }
            cout << "}" << endl;
            cout << "Kalan Matris:" << endl;
            yazdir(matrix, satirEtiket, sutunEtiket);
            continue;
        }

        size_t satir_oncesi = satirEtiket.size();
        size_t sutun_oncesi = sutunEtiket.empty() ? 0 : sutunEtiket.size();

        sadeles_satir(matrix, satirEtiket);
        sadeles_sutun(matrix, sutunEtiket);

        if (satirEtiket.size() < satir_oncesi || (!sutunEtiket.empty() && sutunEtiket.size() < sutun_oncesi))
        {
            cout << "Sadelestirme yapildi." << endl;
            cout << "Kalan Matris:" << endl;
            yazdir(matrix, satirEtiket, sutunEtiket);
            continue;
        }

        cout << "Sadelesicek satir yok sezgisel algoritma uygulanmali." << endl;
        islem_sezgisel_silme(matrix, satirEtiket);
        cout << "Kalan Matris:" << endl;
        yazdir(matrix, satirEtiket, sutunEtiket);
    }

    cout << "\n--- ALGORITMA TAMAMLANDI ---" << endl;
    cout << "Pi Cozum Kumesi: { ";
    for (const auto &item : pi_kumesi)
    {
        cout << item << " ";
    }
    cout << "}" << endl;

    if (!matrix.empty() && !matrix[0].empty())
    {
        cout << "Algoritma bitti ancak matris hala bos degil. Cozum eksik olabilir." << endl;
        cout << "Kalan son matris:" << endl;
        yazdir(matrix, satirEtiket, sutunEtiket);
    }

    return 0;
}
