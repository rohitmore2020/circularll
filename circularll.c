#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create();
void traverse(Node* head);
void insert_beg(Node** head, int value);
void insert_end(Node** head, int value);
void delete_beg(Node** head);
void delete_end(Node** head);

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nCircular Singly Linked List Menu:\n");
        printf("1. Create\n");
        printf("2. Traverse\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create();
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_beg(&head, value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
            case 5:
                delete_beg(&head);
                break;
            case 6:
                delete_end(&head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Node* create() {
    int value;
    Node* newNode;
    Node* head = NULL;
    Node* tail = NULL;

    printf("Enter value (enter -1 to stop): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    return head;
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void insert_beg(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        newNode->next = *head;
        tail->next = newNode;
        *head = newNode;
    }
}

void insert_end(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = *head;
    }
}

void delete_beg(Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = temp->next;
        *head = temp->next;
        free(temp);
    }
}

void delete_end(Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}
