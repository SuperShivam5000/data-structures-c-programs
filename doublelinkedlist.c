// gcc -o p doublelinkedlist.c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void insert_at_start()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insert_at_end()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
    }
}

void insert_at_index()
{
    int ind, i;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d", &newnode->data);
    printf("Enter index to insert at: ");
    scanf("%d", &ind);
    struct node *temp = head;
    for (i = 0; i < ind; i++, temp = temp->next)
    {
        if (temp->next == NULL)
        {
            printf("Index does not exist\n");
            exit(0);
        }
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode; // missed
}

void delete_from_start()
{
    if (head == NULL)
    {
        printf("Empty List!\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL; // missed
        free(temp);
    }
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("Empty List!\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_at_index()
{
    int i, ind;
    printf("Enter index to delete at: ");
    scanf("%d", &ind);
    struct node *temp = head;
    for (i = 0; i < ind; i++, temp = temp->next)
    {
        if (temp->next == NULL)
        {
            printf("Index does not exist\n");
            exit(0);
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void traverse()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        struct node *temp;
        for (temp = head; temp != NULL; temp = temp->next)
        {
            printf("%d\n", temp->data);
        }
    }
}

void print_reverse()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
            ;
        struct node *tail = temp;
        for (temp = tail; temp != NULL; temp = temp->prev)
        {
            printf("%d\n", temp->data);
        }
    }
}

void main()
{
    int c;
    while (1)
    {
        printf("1-Insert at starting\n");
        printf("2-Insert at end\n");
        printf("3-Insert at index\n");
        printf("4-Delete at starting\n");
        printf("5-Delete at end\n");
        printf("6-Delete at index\n");
        printf("7-Traverse\n");
        printf("8-Print in reverse\n");
        printf("9-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_at_start();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_index();
            break;
        case 4:
            delete_from_start();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            delete_at_index();
            break;
        case 7:
            traverse();
            break;
        case 8:
            print_reverse();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}