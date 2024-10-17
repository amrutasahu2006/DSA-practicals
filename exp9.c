#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) { 
        return createNode(data);
    }

    if (data < root->data) {  
        root->left = insert(root->left, data);
    } else if (data > root->data) { 
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;  
    }

    if (key < root->data) {
        return search(root->left, key);  
    }
    return search(root->right, key);  
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left); 
        printf("%d ", root->data);     
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Node %d found in the BST.\n", key);
    } else {
        printf("Node %d not found in the BST.\n", key);
    }

    return 0;
}
