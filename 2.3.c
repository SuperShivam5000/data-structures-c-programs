// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int r,c,i,j,nonzeroes=0;
    printf("Enter No. of Rows: ");
    scanf("%d", &r);
    printf("Enter No. of Columns: ");
    scanf("%d", &c);
    int arr[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter Element: ");
            scanf("%d", &arr[i][j]);
            if(arr[i][j]!=0) nonzeroes++;
        }
    }
    int tupple[nonzeroes+1][3];
    tupple[0][0] = r;
    tupple[0][1] = c;
    tupple[0][2] = nonzeroes;
    
    int count=1;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(arr[i][j]!=0) {
                tupple[count][0]=i;
                tupple[count][1]=j;
                tupple[count][2]=arr[i][j];
                count++;
            }
        }
    }
    
    for(i=0;i<nonzeroes+1;i++){
        for(j=0;j<3;j++){
            printf("%d ",tupple[i][j]);
        }
        printf("\n");
    }

    return 0;
}