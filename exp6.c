#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data;
    struct Node* next;
};
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = strdup(data);  
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, char* data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Change '%s' pushed to undo stack\n", data);
}
char* pop(struct Node** top) {
    if (*top == NULL) {
        printf("Undo stack is empty\n");
        return NULL;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    char* poppedData = temp->data;
    free(temp);
    return poppedData;
}
void textEditor() {
    struct Node* undoStack = NULL;
    char* text = strdup("Hello");
    
    printf("Initial text: %s\n", text);

    push(&undoStack, text);  
    text = strdup("Hello, World!");
    printf("Typed: %s\n", text);

    push(&undoStack, text);  
    text = strdup("Hello, World! How are you?");
    printf("Typed: %s\n", text);

    char* lastChange = pop(&undoStack);
    if (lastChange) {
        free(text);
        text = lastChange;
        printf("After undo: %s\n", text);
    }

    lastChange = pop(&undoStack);
    if (lastChange) {
        free(text);
        text = lastChange;
        printf("After undo: %s\n", text);
    }
    free(text);
}

int main() {
    textEditor();
    return 0;
}