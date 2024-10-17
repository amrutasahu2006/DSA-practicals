#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; 
    newNode->prev = newNode; 
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *curr = *head, *prevNode = NULL;

    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with value %d not found.\n", key);
            return;
        }
        prevNode = curr;
        curr = curr->next;
    }

    if (curr->next == *head && curr->prev == *head) {
        *head = NULL;
        free(curr);
        return;
    }

    if (curr == *head) {
        prevNode = (*head)->prev;
        *head = (*head)->next;
        prevNode->next = *head;
        (*head)->prev = prevNode;
        free(curr);
    } else if (curr->next == *head) {
        prevNode->next = *head;
        (*head)->prev = prevNode;
        free(curr);
    } else {
        struct Node* temp = curr->next;
        prevNode->next = temp;
        temp->prev = prevNode;
        free(curr);
    }
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Circular Doubly Linked List: ");
    displayList(head);

    printf("Deleting node with value 20.\n");
    deleteNode(&head, 20);
    printf("Updated List: ");
    displayList(head);

    return 0;
}
