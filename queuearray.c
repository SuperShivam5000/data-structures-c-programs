// gcc -o p queuearray.c
#include <stdio.h>
#include <stdlib.h>

int *arr;
int front = -1;
int rear = -1;
int n;

void createarray()
{
    printf("Enter size of array: ");
    scanf("%d", &n);
    arr = calloc(n, sizeof(int));
}

void insert()
{
    if (front == n - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        int x;
        printf("Enter element to insert: ");
        scanf("%d", &x);
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = x;
        }
        else
        {
            front++;
            arr[front] = x;
        }
    }
}

void delete()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        printf("Deleted element: %d\n", arr[rear]);
        rear = -1;
        front = -1;
    }
    else
    {
        printf("Deleted element: %d\n", arr[rear]);
        rear++;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = rear; i <= front; i++)
        {
            printf("%d\n", arr[i]);
        }
    }
}

void isEmpty()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}

void isFull()
{
    if (front == n - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }
}

int main()
{
    createarray();
    int c;
    while (1)
    {
        printf("1-Insert\n2-Delete\n3-Display\n4-Check If Empty\n5-Check If Full\n6-Exit\nEnter your choice: ");
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
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
    return 0;
}