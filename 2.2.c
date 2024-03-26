// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r,c,i,j,count=0;
    printf("Enter No. of Rows: ");
    scanf("%d", &r);
    printf("Enter No. of Columns: ");
    scanf("%d", &c);
    int arr[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter Element: ");
            scanf("%d", &arr[i][j]);
        }
    }
    
    //Find non-zero elements
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if (arr[i][j]==0)count++;
        }
    }
    printf("No. of non-zero elements = %d \n", count);
    
    //Print upper triangular matrix
        printf("Upper Triangular Matrix: \n");
        for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if (j>=i) printf("%d ", arr[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
    
        //Print elements just above and below the main diagonal
        printf("Elements just above and below the main diagonal: \n");
        for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if (abs(i-j)==1) printf("%d ", arr[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
    return 0;
}