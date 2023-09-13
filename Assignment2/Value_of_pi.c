#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <time.h>
int main()
{

    clock_t start, end;
    start = clock();

    int total_points = 100000000; // Total number of points
    int points_inside_circle = 0; // Counter for points inside the quarter circle

    // Seed the random number generator
    srand(time(NULL));

#pragma omp parallel for num_threads(16) reduction(+ : points_inside_circle)
    for (int i = 0; i < total_points; i++)
    {
        double x = (double)rand() / RAND_MAX; // Random x-coordinate
        double y = (double)rand() / RAND_MAX; // Random y-coordinate

        // Check if the point is inside the quarter circle
        if (x * x + y * y <= 1.0)
        {
            points_inside_circle++;
        }
    }

    // Calculate the estimated value of Pi
    double estimated_pi = 4.0 * points_inside_circle / total_points;

    printf("Estimated value of Pi: %lf\n", estimated_pi);

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);
    return 0;
}
