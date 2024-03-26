#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertNode(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void printList()
{
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void thirdlast()
{
    int c, c2;
    c = 0;
    struct Node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        c++;
    }
    c2 = c - 2;
    int i = 1;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (i == c2)
            break;
        i++;
    }
    printf("Third Last Element: %d", temp->data);
}
int main()
{
    int num_elements, data;

    printf("Enter the number of elements for the linked list: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements:\n", num_elements);
    for (int i = 0; i < num_elements; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertNode(data);
    }

    printList();
    thirdlast();

    return 0;
}
