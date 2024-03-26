//gcc -o p reversestringusingstack.c
#include <stdio.h>
#include <stdlib.h>
//Implementation of stack in C

struct node{
    char data;
    struct node *next;
} *head, *top;

void push(char n){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL){
        head=newnode;
        top=head;
    } else {
        top->next=newnode;
        top=top->next;
    }
}

void pop(){
    if(head==NULL){
        printf("Stack Underflow");
        return;
    }
    if(top==head){
        free(head);
        head=top=NULL;
        return;
    }

    struct node *temp=head;
    while (temp->next != top) {
            temp = temp->next;
    }
    free(top);
    top=temp;
}

char peek(){
    if(head==NULL){
        printf("Stack is empty");
        exit(0);
    }
    return top->data;
}

int main(){
    int i,n;
    printf("Enter length of string");
    scanf("%d", &n);
    char str[n + 1]; // +1 for the null terminator
    printf("Enter String: ");
    scanf(" %20[^\n]", str); // Limit to reading at most 20 characters, adjust as needed
    for(i=0;str[i]!='\0';i++){
        push(str[i]);
    }
    char str2[n];
    for(i=0;str[i]!='\0';i++){
        str2[i]=peek();
        pop();
    }
    printf("Reversed String: %s", str2);

}