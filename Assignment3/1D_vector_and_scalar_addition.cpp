#include <iostream>
#include <vector>
#include <omp.h>
#include <time.h>

using namespace std;
int main()
{
    clock_t start, end;
    start = clock();
    int n = 200000000;
    vector<int> v(n, 3);
    int b = 6;
#pragma omp parallel for num_threads(8) schedule(static, 1000000) firstprivate(b)
    for (int i = 0; i < n; i++)
    {
        v[i] = v[i] + b;
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);
    return 0;
}