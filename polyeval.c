// gcc -o p polyeval.c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
} *head;

void createpoly()
{
    head = NULL;
    struct node *temp = head;
    int i, d;
    printf("Enter degree of polynomial: ");
    scanf("%d", &d);
    for (i = d; i >= 0; i--)
    {
        struct node *newnode = malloc(sizeof(struct node));
        newnode->exp = i;
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &newnode->coeff);
        if (temp == NULL)
        {
            temp = newnode;
            head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

void printpoly()
{
    if (head == NULL)
    {
        printf("Empty Polynomial\n");
        return;
    }
    struct node *temp;
    printf("Entered polynomial : ");
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%dx^%d ", temp->coeff, temp->exp);
    }
    printf("\n");
}

void evalpoly()
{
    int i, x, tempx;
    int s = 0;
    printf("Enter value of x: ");
    scanf("%d", &x);
    struct node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        // printf("%dx^%d ", temp->coeff, temp->exp);
        tempx = temp->coeff;
        for (i = 1; i <= temp->exp; i++)
        {
            tempx = tempx * x;
        }
        s = s + tempx;
    }
    printf("Value = %d\n", s);
}

void main()
{
    int c;
    while (1)
    {
        printf("1-Create Polynomial\n");
        printf("2-Print Polynomial\n");
        printf("3-Evaluate Polynomial\n");
        printf("4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            createpoly();
            break;
        case 2:
            printpoly();
            break;
        case 3:
            evalpoly();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
}