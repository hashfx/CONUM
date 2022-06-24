#include <stdio.h>
#include <math.h>
#define e 0.001 // minimum precising value: value of program must not be below this value
#define f(x) x*x*x - 4 * x + 1
#define df(x) 3 * x *x - 4 // derivative of f(x)

int main()
{
    // x0: input; x1: root value; f0: f(x0); f1: f(x1); df0: df(x0)
    float x0, x1, f0, f1, df0;
    int i; // number of iterations

    printf("Enter x0: ");
    scanf("%f", &x0);
    do
    {
        f0 = f(x0);
        df0 = df(x0);
        // formula
        x1 = x0 - (f0 / df0);
        f1 = f(x1);
        x0 = x1; // value of x0 = new value of x1
        i++;     // interation increased
        printf("Number of iterations: %d", i);
        printf("\tRoot: %f", x1);
        printf("\tValue of Function: %f\n", f1);
    } while (fabs(f1) > e);

    return 0;
}
