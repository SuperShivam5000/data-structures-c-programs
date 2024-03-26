// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int isPrime(int n){
    int i,c=0;
    for(i=1;i<=n;i++) {
        if(n%i==0) c++;
    }
    if(c==2) return 1; else return 0;
    }
int main() {
   int i,j,c,l;
   printf("Enter Length: ");
   scanf("%d", &l);
   int *arr;
   arr = (int*) calloc(l, sizeof(int));

   for(i=0;i<l;i++){
    printf("Enter Element: ");
    scanf("%d", &arr[i]);
   }
   for(i=0;i<l;i++){
    if (isPrime(arr[i])==1)printf("%d", arr[i]);
   }
   free(arr);
   return 0;
}
