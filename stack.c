// gcc -o p stack.c
#include <stdio.h>
#include <stdlib.h>

int arr[5];
int top = -1;

void push()
{
    int num;
    printf("Enter element to push: ");
    scanf("%d", &num);
    int n = sizeof(arr) / sizeof(int);
    if (top == n - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    arr[top] = num;
    printf("%d has been added to the stack\n", num);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    int temp = arr[top];
    top--;
    printf("Popped Element: %d\n", temp);
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Element: %d\n", arr[top]);
}

int main()
{
    int c, a;
    while (1)
    {
        printf("1 for push\n2 for pop\n3 for peek\n4 for exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
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