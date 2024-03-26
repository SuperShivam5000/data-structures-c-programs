#include <stdio.h>
#include <stdlib.h>
//Implementation of stack in C

struct node{
    int data;
    struct node *next;
} *head, *top;

void push(){
    int n;
    printf("Enter element to be pushed: ");
    scanf("%d", &n);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL){
        head=newnode;
        top=head;
    } else {
        top->next=newnode;
        top=top->next;
    }
    printf("%d has been inserted", n);
}

void pop(){
    if(head==NULL){
        printf("Stack Underflow");
        return;
    }
    if(top==head){
        printf("Popped Element: %d", head->data);
        free(head);
        head=top=NULL;
        return;
    }

    int x=top->data;
    struct node *temp=head;
    while (temp->next != top) {
            temp = temp->next;
    }
    free(top);
    top=temp;
    printf("Popped Element: %d", x);
}

void peek(){
    if(head==NULL){
        printf("Stack is empty");
        return;
    }
    printf("Element: %d",top->data);
}

int main(){
    int c,a;
    while(1){
        printf("1 for push\n2 for pop\n3 for peek\n4 for exit\nEnter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: exit(0); break;
            default: printf("Invalid Choice"); break;
        }
    }
}