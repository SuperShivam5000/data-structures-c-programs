// gcc -o p polynomialadd.c
#include <stdio.h>
#include <stdlib.h>

void printpoly(int *arr, int n)
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        printf("%dx^%d ", arr[i], i);
    }
    printf("\n");
}

int main()
{
    int i;
    int n1;
    int *arr1;
    printf("Enter degree of first polynomial: ");
    scanf("%d", &n1);
    arr1 = malloc(n1 * sizeof(int));
    for (i = n1 - 1; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("First polynomial: ");
    printpoly(arr1, n1);
    int n2;
    int *arr2;
    printf("Enter degree of second polynomial: ");
    scanf("%d", &n2);
    arr2 = malloc(n2 * sizeof(int));
    for (i = n2 - 1; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &arr2[i]);
    }
    printf("Second polynomial: ");
    printpoly(arr2, n2);
    int *sum;
    int sumlength;
    if (n1 > n2)
    {
        sum = malloc(n1 * sizeof(int));
        sumlength = n1;
        for (i = 0; i < n1; i++)
        {
            sum[i] = arr1[i];
        }
        for (i = 0; i < n2; i++)
        {
            sum[i] += arr2[i];
        }
    }
    else
    {
        sum = malloc(n2 * sizeof(int));
        sumlength = n2;
        for (i = 0; i < n2; i++)
        {
            sum[i] = arr2[i];
        }
        for (i = 0; i < n1; i++)
        {
            sum[i] += arr1[i];
        }
    }
    printf("Sum: ");
    printpoly(sum, sumlength);
    return 0;
}