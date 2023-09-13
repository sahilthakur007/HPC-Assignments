#include <iostream>
#include <vector>
#include <omp.h>
#include <time.h>
using namespace std;
const int N = 1000;

int main()
{

    clock_t start, end;
    start = clock();
    vector<vector<int>> matrix1(N, vector<int>(N, 1));
    vector<vector<int>> matrix2(N, vector<int>(N, 2));

    vector<vector<int>> result(N, vector<int>(N, 0));
    // omp_set_num_threads(8);

#pragma omp parallel for num_threads(8) schedule(static, 250)
    for (int i = 0; i < N; i++)
    {
#pragma omp parallel for num_threads(8) schedule(static, 250)
        for (int j = 0; j < N; j++)
        {
            // #pragma omp parallel for schedule(static, 250)
            for (int k = 0; k < N; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);
    return 0;
}