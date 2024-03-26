#include <stdio.h>

void printpoly(int poly[], int n) {
    int i;
    for (i = n; i >= 0; i--) {
        printf("%dx^%d ", poly[i], i);
    }
    printf("\n");
}

int main() {
    int n1, n2, nmax, nmin, i;
    printf("Enter degree of polynomial 1: ");
    scanf("%d", &n1);
    int poly1[n1 + 1];
    for (i = n1; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    printpoly(poly1, n1);

    printf("Enter degree of polynomial 2: ");
    scanf("%d", &n2);
    int poly2[n2 + 1];
    for (i = n2; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }
    printpoly(poly2, n2);

    if (n1 > n2){
        nmax = n1;
        nmin = n2;
    }
    else{
        nmax = n2;
        nmin = n1;
    }
    int sum[nmax + 1];
    for (i = nmax; i > nmin; i--) {
        sum[i] = poly1[i];
    }
    for(i=nmin; i>=0; i--){
        sum[i] = poly1[i] + poly2[i];
    }
    printf("Sum: \n");
    printpoly(sum, nmax);

    return 0;
}