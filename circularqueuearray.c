// gcc -o p circularqueuearray.c
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
    if (rear == -1 && front == -1) // checks if empty
    {
        rear++;
        front++;
        printf("Enter an element: ");
        scanf("%d", &arr[front]);
        printf("Inserted element: %d\n", arr[front]);
    }
    else if (front == n - 1 && rear != 0) // checks if front is at end of array and rear is not at zero
    {
        front = 0;
        printf("Enter an element: ");
        scanf("%d", &arr[front]);
        printf("Inserted element: %d\n", arr[front]);
    }
    else if ((front == n - 1 && rear == 0) || (front == rear - 1)) // checks if array is full
    {
        printf("Overflow!\n");
    }
    else // insert normally
    {
        front++;
        printf("Enter an element: ");
        scanf("%d", &arr[front]);
        printf("Inserted element: %d\n", arr[front]);
    }
}

void delete()
{
    if (front == -1 && rear == -1) // checks if empty
    {
        printf("Underflow\n");
    }
    else if (front == rear) // checks if only one element
    {
        printf("Deleted element: %d\n", arr[rear]);
        rear = -1;
        front = -1;
    }
    else if (rear == n - 1) // checks if rear is at the end of the list
    {
        printf("Deleted element: %d\n", arr[rear]);
        rear = 0;
    }
    else // delete normally
    {
        printf("Deleted element: %d\n", arr[rear]);
        rear++;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1) // check if empty
    {
        printf("Queue is empty\n");
    }
    else if (rear <= front) // check if rear is behind front
    {
        for (i = rear; i <= front; i++)
        {
            printf("%d\n", arr[i]);
        }
    }
    else // if front is behind rear
    {
        // print from rear to n then from 0 to front
        for (i = rear; i < n; i++)
        {
            printf("%d\n", arr[i]);
        }
        for (i = 0; i <= front; i++)
        {
            printf("%d\n", arr[i]);
        }
    }
}

int main()
{
    createarray();
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
            printf("Invalid choice!");
            break;
        }
    }
    return 0;
}