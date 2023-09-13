#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <iostream>
using namespace std;
#define BUFFER_SIZE 10000
int buffer[BUFFER_SIZE];
int itemCount = 0;

void producer()
{
#pragma omp parallel
    {

        for (int i = 0; i < 10000; ++i)
        {
            // cout << "Adding data by producer " << i << " using thread " <<  omp_get_thread_num() << " and total threads are  " << omp_get_num_threads() << endl;

#pragma omp task
            {

                // cout << "Adding data by producer " << i << " task  using thread " << omp_get_thread_num() << " and total threads are  " << omp_get_num_threads() << endl;
#pragma omp critical
                {   
                    // while(itemCount>=BUFFER_SIZE)
                        ;
                    if (itemCount < BUFFER_SIZE)
                    {
                        buffer[itemCount++] = i;
                        printf("Produced: %d\n", i);
                    }
                }
            }
        }
    }
}

void consumer()
{
#pragma omp parallel
    {
        for (int i = 0; i < 10000; ++i)
        {
            // cout << "removing data by consumer " << i << " using thread " <<  omp_get_thread_num() << " and total threads are  " << omp_get_num_threads() << endl;
#pragma omp task
            {
                // cout << "removing data by consumer  " << i << " task using thread " << omp_get_thread_num() << " and total threads are  " << omp_get_num_threads() << endl;
#pragma omp critical
                {
                    // while (itemCount <=0)
                        ;
                    if (itemCount > 0)
                    {
                        int consumedItem = buffer[--itemCount];
                        printf("Consumed: %d\n", consumedItem);
                    }
                }
            }
        }
    }
}

int main()
{
    // omp_set_num_threads(4);

    clock_t start, end;
    start = clock();

#pragma omp parallel sections num_threads(4)
    {
#pragma omp section
        {
            producer();
        }

#pragma omp section
        {
            consumer();
        }
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);
    return 0;
}