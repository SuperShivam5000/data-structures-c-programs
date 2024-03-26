#include <stdio.h>
#include <stdlib.h>

struct node {
    int exp;
    int coeff;
    struct node *next;
};

void printpoly(struct node *head){
    struct node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

struct node * inputpoly(struct node *head, int n){
    int i;
    struct node *temp;
    temp = head;
    temp->exp=n;
    printf("Enter coefficient of x^%d: ", n);
    scanf("%d",&temp->coeff);
    for(i=n-1;i>=0;i--){
        temp->next = (struct node*) malloc(sizeof(struct node));
        temp=temp->next;
        temp->exp=i;
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d",&temp->coeff);
    }
    return head;
}

struct node * sumpoly(struct node *head1, struct node *head2){
    struct node *temp1 = head1, *temp2 = head2, *sum = NULL, *temp3 = NULL;
    while (temp1 != NULL || temp2 != NULL) {
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        new_node->next = NULL;
        if (temp1 != NULL && temp2 != NULL) {
            if (temp1->exp == temp2->exp) {
                new_node->exp = temp1->exp;
                new_node->coeff = temp1->coeff + temp2->coeff;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->exp > temp2->exp) {
                new_node->exp = temp1->exp;
                new_node->coeff = temp1->coeff;
                temp1 = temp1->next;
            } else {
                new_node->exp = temp2->exp;
                new_node->coeff = temp2->coeff;
                temp2 = temp2->next;
            }
        } else if (temp1 != NULL) {
            new_node->exp = temp1->exp;
            new_node->coeff = temp1->coeff;
            temp1 = temp1->next;
        } else {
            new_node->exp = temp2->exp;
            new_node->coeff = temp2->coeff;
            temp2 = temp2->next;
        }
        if (sum == NULL) {
            sum = new_node;
            temp3 = sum;
        } else {
            temp3->next = new_node;
            temp3 = new_node;
        }
    }
    return sum;
}

int main() {
    struct node *head1,*head2,*sum;
    int n1,n2;

    //input head1
    head1 = (struct node*) malloc(sizeof(struct node));
    printf("Enter degree of first polynomial: ");
    scanf("%d", &n1);
    head1 = inputpoly(head1,n1);
    //input head2
    head2 = (struct node*) malloc(sizeof(struct node));
    printf("Enter degree of second polynomial: ");
    scanf("%d", &n2);
    head2 = inputpoly(head2,n2);
    //print polynomials
    printf("Polynomial 1: ");
    printpoly(head1);
    printf("Polynomial 2: ");
    printpoly(head2);
    //print sum
    sum = (struct node*) malloc(sizeof(struct node));
    sum = sumpoly(head1,head2);
    printf("Sum: ");
    printpoly(sum);
}