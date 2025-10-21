#include "../include/library.h"

vector<vector<int>> generateRandomMatrix()
{
    srand(time(0));

    int row = (rand() % 9) + 1;
    int col = (rand() % 9) + 1;

    vector<vector<int>> matrix(row, vector<int>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}
