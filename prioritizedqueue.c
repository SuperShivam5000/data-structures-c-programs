// gcc -o p prioritizedqueue.c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
} *rear = NULL, *front = NULL;

void insert() // insert in descending order of priority
{
    int n, p;
    printf("Enter element to insert: ");
    scanf("%d", &n);
    printf("Enter priority of the element: ");
    scanf("%d", &p);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->priority = p;
    if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        if (newnode->priority > rear->priority)
        {
            // insert newnode before rear
            newnode->next = rear;
            rear = newnode;
        }
        else if (newnode->priority < front->priority)
        {
            // insert newnode after front
            front->next = newnode;
            front = newnode;
        }
        else
        {
            struct node *temp;
            for (temp = rear; temp != front; temp = temp->next)
            {
                if (temp->priority > newnode->priority && temp->next->priority < newnode->priority)
                {
                    // insert newnode after temp and before temp->next
                    newnode->next = temp->next;
                    temp->next = newnode;
                }
            }
        }
    }
    printf("%d has been inserted with priority %d\n", n, p);
}

void delete() // delete at beginning function
{
    if (rear == NULL && front == NULL)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        printf("%d has been deleted, had priority %d\n", rear->data, rear->priority);
        free(rear);
        rear = NULL;
        front = NULL;
    }
    else
    {
        struct node *temp = rear;
        rear = rear->next;
        printf("%d has been deleted, had priority %d\n", temp->data, temp->priority);
        free(temp);
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
            printf("%d, priority=%d\n", temp->data, temp->priority);
        }
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("1-Insert\n2-Delete\n3-Display\n4-Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}