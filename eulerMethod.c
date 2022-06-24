#include <stdio.h>
#include <math.h>
#define f(x, y) -x *y // dy/dx + xy = 0
int main()
{
    float a, b, x, y, t, k, h;
    
    printf("Enter value of x0 y0 h xn: ");
    scanf("%f %f %f %f", &a, &b, &h, &t);

    // values of (a, b) would be changed simultaneously, so initial user input is stored in x, y
    x = a;
    y = b;

    while (x<t)  // loop until initial value (x) is smaller than final value (t)
    {
        k = h*f(x, y);  // euler method formula
        y = y+k;
        x=x+h;;
        printf("x: %f\ty: %f\n", x, y);
    }
    
    return 0;
}
