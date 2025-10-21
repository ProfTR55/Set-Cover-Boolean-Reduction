#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// Fonksiyon deklarasyonları
vector<vector<int>> generateRandomMatrix();
void yazdir(const vector<vector<int>> &matrix, const vector<string> &satirEtiket, const vector<string> &sutunEtiket);
bool islem_mutlak(vector<vector<int>> &M, vector<string> &satirEtiket, vector<string> &sutunEtiket, set<string> &pi_kumesi);
void sadeles_satir(vector<vector<int>> &M, vector<string> &satirEtiket);
void sadeles_sutun(vector<vector<int>> &M, vector<string> &sutunEtiket);
void islem_sezgisel_silme(vector<vector<int>> &M, vector<string> &satirEtiket);

#endif
