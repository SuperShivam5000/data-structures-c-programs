#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int element)
{
    if (isFull(stack))
    {
        printf("Stack overflow!\n");
        return;
    }

    stack->data[++stack->top] = element;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        return -1;
    }

    return stack->data[stack->top--];
}

void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void copyStack(Stack *source, Stack *destination)
{
    Stack tempStack;
    initialize(&tempStack);

    while (!isEmpty(source))
    {
        int element = pop(source);
        push(&tempStack, element);
    }

    while (!isEmpty(&tempStack))
    {
        int element = pop(&tempStack);
        push(destination, element);
        push(source, element);
    }
}

int main()
{
    Stack sourceStack, destinationStack;
    initialize(&sourceStack);
    initialize(&destinationStack);

    push(&sourceStack, 10);
    push(&sourceStack, 20);
    push(&sourceStack, 30);
    push(&sourceStack, 40);
    push(&sourceStack, 50);

    printf("Source stack: ");
    display(&sourceStack);

    copyStack(&sourceStack, &destinationStack);

    printf("Destination stack: ");
    display(&destinationStack);

    printf("Source stack after copying: ");
    display(&sourceStack);

    return 0;
}