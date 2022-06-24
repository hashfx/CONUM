#include <stdio.h>
#include <math.h>
#define e 0.001 // minimum precising value: value of program must not be below this value
#define f(x) x *x *x - 4 * x + 1

void main()
{
    int i = 0; // initial iteration
    float x0, x1, x2, f0, f1, f2;
    // take input
    printf("Enter x0 and x1: ");
    scanf("%f %f", &x0, &x1);

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        f2 = f(x2);

        x2 = ((x0 * f1) - (x1 * f0)) / (f1 - f0);
        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        i++; // perform next iteration
        printf("Number of iterations: %d", i);
        printf("\tRoot: %f", x2);
        printf("\tValue of Function: %f\n", f2);

    } while (fabs(f2) > e);
}
