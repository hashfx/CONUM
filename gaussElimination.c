#include <stdio.h>

int main()
{
    int i, j, k, n;                       // n is order of matrix
    float a[20][20], c, x[10], sum = 0.0; // 2D matrix

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter elements of Augmented Matrix row wise:\n");

    // take matrix input
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n + 1); j++) // number of col is row+1
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // calculation

    // elementary row operation
    for (j = 0; j <= n; j++) // column
    {
        for (i = 0; i <= n; i++) // row
        {
            if (i > j) // for a21, a31, a32
            {
                c = a[i][j] / a[j][j];       // ratio
                for (k = 0; k <= n + 1; k++) // to perform row operation on each element of complete row
                {
                    a[i][k] = a[i][k] - c * a[j][k];
                }
            }
        }
    }

    x[n] = a[n][n + 1] / a[n][n]; // for value of x[(1, 2, 3)]
    // backward substitution
    for (i = n - 1; i >= 1; i--) // we already have value of x3, now for x2 and x1
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (a[i][n + 1] - sum) / a[i][i];
    }
    printf("\nSolution is:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\nx%d = %f\t", i, x[i]);  // solutions of x1, x2, x3
    }

    return 0;
}
