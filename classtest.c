#include <stdio.h>
#include <stdlib.h>

int main() {
    // Take input for the array
    int n, i;
    printf("Enter Number Of Elements in array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Enter Element: ");
        scanf("%d", &arr[i]);
    }

    // Find min and max
    int min = arr[0], max = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Max = %d \n", max); // Removed the & before max
    printf("Min = %d \n", min); // Removed the & before min

    // Insert element
    int ele, ind;
    printf("Enter Element: ");
    scanf("%d", &ele); // Removed the comma before &ele
    printf("Enter Index: ");
    scanf("%d", &ind); // Removed the comma before &ind
    for (i = n; i > ind; i--) { // Changed i++ to i--
        arr[i] = arr[i - 1];
    }
    arr[ind] = ele;

    // Print new array
    printf("New Array: \n");
    for (i = 0; i < n + 1; i++) { // Changed n to n+1 to print the updated array
        printf("%d \n", arr[i]); // Removed the & before arr[i]
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
