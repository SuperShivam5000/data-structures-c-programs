#include <stdio.h>
#include <stdlib.h>

int** retArr()
{
    int r,c,i;
    printf("Enter No. Of Rows ");
    scanf("%d", &r);
    int** a = (int**)malloc(r * sizeof(int*));
    printf("Enter No. Of Columns ");
    scanf("%d", &c);
    for (int i = 0; i < r; i++) a[i] = (int*)malloc(c * sizeof(int));

    // Initialize the array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter Element");
            scanf("%d", &a[i][j]);
        }
    }

    return a;
}

int main()
{
    int** a = retArr();
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Don't forget to free the dynamically allocated memory when you're done with it.
    for (int i = 0; i < 3; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}
