// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,k,r1,r2;
    printf("Enter number of rows in first sparse matrix: ");
    scanf("%d", &r1);
    int sparse1[r1][3];
    for(i=0;i<r1;i++){
        for(j=0;j<3;j++){
            printf("Enter element: ");
            scanf("%d", &sparse1[i][j]);
        }
    }
    printf("Enter number of rows in second sparse matrix: ");
    scanf("%d", &r2);
    int sparse2[r2][3];
    for(i=0;i<r2;i++){
        for(j=0;j<3;j++){
            printf("Enter element: ");
            scanf("%d", &sparse2[i][j]);
        }
    }
    int sum[r1+r2][3];
    if(sparse1[0][0]!=sparse2[0][0] && sparse1[0][1]!=sparse2[0][1]) {
        printf("Orders must be same for addition");
        exit(0);
    }
    sum[0][0]=sparse1[0][0];
    sum[0][1]=sparse1[0][1];
    i=1;j=1;k=1;
        while(i<r1 && j<r2){
            if(sparse1[i][0]==sparse2[j][0]){
                if(sparse1[i][1]==sparse2[j][1]){
                    sum[k][0]=sparse1[i][0];
                    sum[k][1]=sparse1[i][1];
                    sum[k][2]=sparse1[i][2]+sparse2[j][2];
                    i++;
                    j++;
                    k++;
                }
                else if(sparse1[i][1]>sparse2[j][1]){
                    sum[k][0]=sparse1[i][0];
                    sum[k][1]=sparse1[i][1];
                    sum[k][2]=sparse1[i][2];
                    i++;
                    k++;
                }
                else if(sparse1[i][1]<sparse2[j][1]){
                    sum[k][0]=sparse2[j][0];
                    sum[k][1]=sparse2[j][1];
                    sum[k][2]=sparse2[j][2];
                    j++;
                    k++;
                }
            } else if(sparse1[i][0]>sparse2[j][0]){
                sum[k][0]=sparse1[i][0];
                sum[k][1]=sparse1[i][1];
                sum[k][2]=sparse1[i][2];
                i++;
                k++;
            } else if (sparse1[i][0]<sparse2[j][0]){
                sum[k][0]=sparse2[j][0];
                sum[k][1]=sparse2[j][1];
                sum[k][2]=sparse2[j][2];
                j++;
                k++;
            }
        }
        while(i<r1){
            sum[k][0]=sparse1[i][0];
            sum[k][1]=sparse1[i][1];
            sum[k][2]=sparse1[i][2];
            i++;
            k++;
        }
        while(j<r2){
            sum[k][0]=sparse2[j][0];
            sum[k][1]=sparse2[j][1];
            sum[k][2]=sparse2[j][2];
            j++;
            k++;
        }
    sum[0][2]=k-1;
    printf("Sum:- \n");
    for(i=0;i<k-1;i++){
        for(j=0;j<3;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}