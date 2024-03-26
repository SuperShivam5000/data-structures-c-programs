#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* insertInMiddle(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    int count = 1;
    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteFromMiddle(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return head;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    int count = 1;
    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

int searchElement(struct Node* head, int element) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == element) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, element, result;

    while (1) {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Create and display a Singly Linked List\n");
        printf("2. Insert a new node at the beginning\n");
        printf("3. Insert a new node at the end\n");
        printf("4. Insert a node in the middle\n");
        printf("5. Delete the first node\n");
        printf("6. Delete a node from the middle\n");
        printf("7. Delete the last node\n");
        printf("8. Search for an element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                int n;
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    head = insertAtEnd(head, data);
                }
                displayList(head);
                break;

            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                displayList(head);
                break;

            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                displayList(head);
                break;

            case 4:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertInMiddle(head, data, position);
                displayList(head);
                break;

            case 5:
                head = deleteFirstNode(head);
                displayList(head);
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                head = deleteFromMiddle(head, position);
                displayList(head);
                break;

            case 7:
                head = deleteLastNode(head);
                displayList(head);
                break;

            case 8:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                result = searchElement(head, element);
                if (result != -1) {
                    printf("Element %d found at position %d\n", element, result);
                } else {
                    printf("Element not found\n");
                }
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}