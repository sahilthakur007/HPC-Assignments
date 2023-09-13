#include <omp.h>

#include <stdio.h>
#include <stdlib.h>
// system("cls");
void printMes()
{
    int tn;
    tn = omp_get_thread_num();
    printf("\nHello world %d \n", tn);
}

int main(int argc, char *argv[])
{
#pragma omp parallel num_threads(5)
    printMes();
    return 0;
}
