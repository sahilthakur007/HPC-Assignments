#include <iostream>
#include <omp.h>
#include <time.h>
#include <vector>
using namespace std;
// const int N = 12000;
const int N = 12000;

int main()
{

    // omp_set_num_threads(8);

    clock_t start, end;
    start = clock();

    // int matrix1[N][N] = {
    //     {1, 0, 0, 0, 0},
    //     {6, 7, 0, 0, 0},
    //     {11, 12, 13, 0, 0},
    //     {16, 17, 18, 19, 0},
    //     {21, 22, 23, 24, 25}};

    // int matrix2[N][N] = {
    //     {5, 0, 0, 0, 0},
    //     {9, 8, 0, 0, 0},
    //     {15, 14, 10, 0, 0},
    //     {20, 19, 18, 11, 0},
    //     {25, 24, 23, 22, 21}};

    vector<vector<int>> result(N, vector<int>(N));
    vector<vector<int>> matrix1(N, vector<int>(N));
    vector<vector<int>> matrix2(N, vector<int>(N));

#pragma omp parallel for schedule(dynamic, 20) num_threads(8)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);

    return 0;
}