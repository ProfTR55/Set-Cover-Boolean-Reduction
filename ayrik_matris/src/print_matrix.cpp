#include "../include/library.h"

void yazdir(const vector<vector<int>> &M, const vector<string> &satirEtiket, const vector<string> &sutunEtiket)
{
    if (M.empty())
    {
        cout << "(Matris bos)\n";
        return;
    }

    cout << setw(5) << " ";
    for (auto &s : sutunEtiket)
        cout << setw(4) << s;
    cout << "\n";

    for (int i = 0; i < M.size(); i++)
    {
        cout << setw(5) << satirEtiket[i];
        for (int j = 0; j < M[i].size(); j++)
            cout << setw(4) << M[i][j];
        cout << "\n";
    }
    cout << "---------------------------\n";
}