#include <iostream>
#include <vector>
#include <omp.h>
#include <time.h>

using namespace std;
int main()
{
    clock_t start, end;
    start = clock();
    // int row = 10000, col = 10000;
    int row = 10000, col = 10000;

    vector<vector<int>> v1(row, vector<int>(col, 1));
    vector<vector<int>> v2(row, vector<int>(col, 2));
    vector<vector<int>> result(row, vector<int>(col));
#pragma omp parallel for num_threads(8) collapse(2)
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = v1[i][j] + v2[i][j];
        }
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);
    return 0;
}