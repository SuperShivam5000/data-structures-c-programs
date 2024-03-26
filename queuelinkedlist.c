#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
void insertNode(struct Node **head_ref, int new_data)
{
    // Allocate memory for a new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Set the data of the new node
    new_node->data = new_data;
    // Set the next of the new node to the current head
    new_node->next = *head_ref;
    // Update the head to point to the new node
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int num_elements, data;

    printf("Enter the number of elements for the linked list: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements:\n", num_elements);
    for (int i = 0; i < num_elements; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Linked List: ");
    printList(head);

    return 0;
}
