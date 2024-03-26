// Online C compiler to run C program online
#include <stdio.h>

int main() {
    //input both sparse matrices
    int r1,r2,i,j;
    printf("Enter No. of rows in first sparse matrix: ");
    scanf("%d", &r1);
    int sparse1[r1][3];
    for(i=0;i<r1;i++){
        for(j=0;j<3;j++){
            printf("Enter Element: ");
            scanf("%d", &sparse1[i][j]);
        }
    }
    printf("Enter No. of rows in second sparse matrix: ");
    scanf("%d", &r2);
    int sparse2[r2][3];
    for(i=0;i<r2;i++){
        for(j=0;j<3;j++){
            printf("Enter Element: ");
            scanf("%d", &sparse2[i][j]);
        }
    }
    
    //convert sparse matrices to normal matrices
    int arr1[sparse1[0][0]][sparse1[0][1]];
    int arr2[sparse2[0][0]][sparse2[0][1]];
    
    for(i=1;i<r1;i++){
        for(j=0;j<3;j++){
            arr1[sparse1[i][0]][sparse1[i][1]]=sparse1[i][2];
        }
    }
    for(i=1;i<r2;i++){
        for(j=0;j<3;j++){
            arr2[sparse2[i][0]][sparse2[i][1]]=sparse2[i][2];
        }
    }
    
    //add normal matrices arr1 and arr2
    int rows,cols;
    if(sparse1[0][0]>sparse2[0][0]) rows=sparse1[0][0];
    else rows = sparse2[0][0];
    if(sparse1[0][1]>sparse2[0][1]) cols=sparse1[0][1];
    else cols = sparse2[0][1];
    int arrsum[rows][cols];
    

    return 0;
}