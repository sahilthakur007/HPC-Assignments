#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
const int N = 200000000;
// const int N = 10000000;
int main()
{
    clock_t start, end;
    start = clock();
    vector<int> a(N, 4);
    vector<int> c(N, 0);

    int b = 4;

#pragma omp parallel for schedule(static, 500) firstprivate(b) num_threads(4)
    for (int i = 0; i < N; i++)
    {
        a[i] = 5;
        c[i] = a[i] + b;
        // printf("%d ", c[i]);
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);

    return 0;
}