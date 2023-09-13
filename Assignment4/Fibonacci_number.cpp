#include <iostream>
#include <omp.h>
#include <time.h>
using namespace std;

int main()
{
    clock_t start, end;
    start = clock();

    int n = 1000000;
    long long prev = 0;
    long long res = 1;

    for (int i = 3; i <= n; i++)
    {

        long long temp = res;
        res = res + prev;
        prev = temp;
    }
    cout << res << endl;
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);
    return 0;
}