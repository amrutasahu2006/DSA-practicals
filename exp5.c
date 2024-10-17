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

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int size = 0;

void insertAtPosition(struct Node* head, int pos, int data)
{
    if (pos < 1 || pos > size + 1)
        printf( "Invalid position!\n" );
    else {
       struct Node *curr=head;
        for(int i=1;i<pos-1;i++) curr = curr->next;
        struct Node* newNode = createNode(data);
        newNode->next=curr->next;
        curr->next = newNode;
        if(pos=1)
        head = newNode;
        size++; 
    }
}

void removeFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
    size--;
}

void removeLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }

    size--;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int searchElement(struct Node* head, int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0; 
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 1);
    

    printf("Linked List: ");
    printList(head);

    deleteNode(&head, 20);
    printf("Linked List after deleting 20: ");
    printList(head);

    deleteNode(&head, 1);
    printf("Linked List after deleting 1: ");
    printList(head);

    int data = 6, pos = 1;
    insertAtPosition(head, pos, data);
    printf("Linked list after insertion of 6 at position 2: ");
    printList(head);
    
    removeLastNode(&head);
    printf("Linked List after deleting Last Node: ");
    printList(head);

    removeFirstNode(&head);
    printf("Linked List after deleting First Node: ");
    printList(head);
    
    int searchVal = 20;
    if (searchElement(head, searchVal)) {
        printf("Element %d is found in the list.\n", searchVal);
    } else {
        printf("Element %d is not found in the list.\n", searchVal);
    }

    return 0;
}
