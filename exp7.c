#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;

        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head;
    }

    printf("Inserted %d at the end\n", data);
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;

        while (temp->next != *head) {
            temp = temp->next;
        }

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }

    printf("Inserted %d at the beginning\n", data);
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head, *prev;

    if (temp->data == key) {
        if (temp->next == *head) { 
            free(temp);
            *head = NULL;
        } else {
            struct Node* last = *head;

            while (last->next != *head) {
                last = last->next;
            }

            *head = (*head)->next;
            last->next = *head;
            free(temp);
        }
        printf("Deleted %d\n", key);
        return;
    }

    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
        printf("Deleted %d\n", key);
    } else {
        printf("%d not found in the list\n", key);
    }
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("%d (head)\n", head->data);
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    traverse(head);

    insertAtBeginning(&head, 5);
    traverse(head);

    deleteNode(&head, 20);
    traverse(head);

    deleteNode(&head, 5);
    traverse(head);

    return 0;
}
