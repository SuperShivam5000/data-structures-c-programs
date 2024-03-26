// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int *arr,l;
void acceptarray(){
    int i;
    printf("Enter length of array: ");
    scanf("%d", &l);
    
    arr = malloc(l * sizeof(int));
    
   for(i=0;i<l;i++){
    printf("Enter Element: ");
    scanf("%d", &arr[i]);
   }
}

void insert(int ind,int ele){
    int i; 
    l++;
    for(i=l;i>ind;i--) arr[i] = arr[i - 1];
    arr[ind] = ele;
}

void delelement(int ind){
    int i;
    for(i=ind;i<l;i++)arr[i]=arr[i+1];
    l--;
}

void search(int ele){
    int i, c=0;
    for(i=0;i<l;i++){
        if(arr[i]==ele) c=1;
    }
    if(c==1) printf("Element Found \n");
    else printf("Element Not Found \n");
}

void traverse(){
    int i;
    for(i=0;i<l;i++){
        printf("%d \n", arr[i]);
    }
}

int main() {
    acceptarray();
    int c,ind,ele;
    
   while(1) {
       printf("Enter Your Choice \n");
       printf("1. Insert \n");
       printf("2. Delete \n");
       printf("3. Linear Search \n");
       printf("4. Traverse \n");
       printf("5. Exit \n");
       printf("Enter Choice: ");
       scanf("%d", &c);
       switch(c){
           case 1:
           printf("Enter Index: ");
           scanf("%d", &ind); 
           printf("Enter Element: ");
           scanf("%d", &ele);
           insert(ind,ele);
           break;
           case 2:
           printf("Enter Index: ");
           scanf("%d", &ind); 
           delelement(ind);
           break;
           case 3:
           printf("Enter Element: ");
           scanf("%d", &ele); 
           search(ele);
           break;
           case 4: 
           traverse(); 
           break;
           case 5:
           free(arr);
           exit(0); 
           break;
           default: printf("Wrong Choice");
       }
   }
    return 0;
}