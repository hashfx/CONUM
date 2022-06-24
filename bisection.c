#include <stdio.h>
#include <math.h>
#define e 0.001
#define f(x) x *x *x - 2 * x - 5 // x*x*x - 4*x + 1

void main()
{
    // initialisation
    float x0, x1, x2; // initial values :: x2 midpoint
    float f0, f1, f2; // expression values
    int i = 0;        // number of steps/approximations

    // input value
    printf("Enter values of x0 and x1: ");
    scanf("%f %f", &x0, &x1);

    do
    {
        f0 = f(x0);         // value of f0 : put x0 at f(x)
        f1 = f(x1);         // value of f1 : put x1 at f(x)
        x2 = (x0 + x1) / 2; // mid value as x2
        f2 = f(x2);         // f2

        // conditions
        if (f0 * f2 < 0)
        { // if f0*f2 is negative
            x1 = x2;
        }
        else
        { // if positive
            x0 = x2;
        }
        i++; // first iteration finished
        printf("Number of iterations: %d", i);
        printf("\tRoot: %f", x2);
        printf("\tValue of Function: %f\n", f2);
    } while (fabs(f2) > e);
}