#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head, *tail;
int n;

void printlist(){
    struct node *temp;
    for(temp=head;temp!=NULL;temp=temp->next){
        printf("%d ", temp->data);
    }
}

void recursion_reverse(int n)
{
    while(n>0){
    struct node *temp=head;
    head = head->next;
    tail->next = (struct node*)malloc(sizeof(struct node));
    tail->next = temp;
    free(temp);
    tail=tail->next;
    }
    recursion_reverse(n-1);
}

int main()
{
    int i;
    printf("Enter number of elements");
    scanf("%d", &n);
    struct node *temp = head;
    for(i=0;i<n;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter an element: ");
        scanf("%d", &temp->data);
        tail = temp;
        temp=temp->next;
    }
    printlist();
    recursion_reverse(n);
    printlist();
}