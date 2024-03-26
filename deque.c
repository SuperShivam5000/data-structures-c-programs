// gcc -o p deque.c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *rear = NULL, *front = NULL;

void insert_start()
{
    int n;
    printf("Enter data to insert: ");
    scanf("%d", &n);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        newnode->next = rear;
        rear = newnode;
    }
    printf("%d has been inserted at the start\n", n);
}

void insert_end()
{
    int n;
    printf("Enter data to insert: ");
    scanf("%d", &n);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        front->next = newnode;
        front = front->next;
    }
    printf("%d has been inserted at the end\n", n);
}

void delete_start()
{
    if (rear == NULL && front == NULL)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        printf("%d has been deleted from start\n", rear->data);
        free(rear);
        rear = NULL;
        front = NULL;
    }
    else
    {
        struct node *temp = rear;
        rear = rear->next;
        printf("%d has been deleted from start\n", temp->data);
        free(temp);
    }
}

void delete_end()
{
    if (rear == NULL && front == NULL)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        printf("%d has been deleted from end\n", rear->data);
        free(rear);
        rear = NULL;
        front = NULL;
    }
    else
    {
        struct node *temp;
        for (temp = rear; temp->next != front; temp = temp->next)
            ;
        printf("%d has been deleted from end\n", front->data);
        free(front);
        front = temp;
        front->next = NULL;
    }
}
void display()
{
    if (rear == NULL && front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp;
        for (temp = rear; temp != NULL; temp = temp->next)
        {
            printf("%d\n", temp->data);
        }
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("1-Insert at beginning\n2-Insert at end\n3-Delete from beginning\n4-Delete from end\n5-Display\n6-Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_start();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            delete_start();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}