#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right, *parent;
    int color; // 0 for Red, 1 for Black
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = 0; // New nodes are red
    return newNode;
}
void rotateLeft(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}
void rotateRight(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL) *root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}
void fixViolation(Node **root, Node *newNode) {
    Node *parent = NULL;
    Node *grandparent = NULL;
    while ((newNode != *root) && (newNode->color == 0) && (newNode->parent->color == 0)) {
        parent = newNode->parent;
        grandparent = parent->parent;
        
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (uncle != NULL && uncle->color == 0) {
                grandparent->color = 0;
                parent->color = 1;
                uncle->color = 1;
                newNode = grandparent;
            } else {
                if (newNode == parent->right) {
                    rotateLeft(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateRight(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                newNode = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if ((uncle != NULL) && (uncle->color == 0)) {
                grandparent->color = 0;
                parent->color = 1;
                uncle->color = 1;
                newNode = grandparent;
            } else {
                if (newNode == parent->left) {
                    rotateRight(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateLeft(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                newNode = parent;
            }
        }
    }
    (*root)->color = 1;
}
void insert(Node **root, int data) {
    Node *newNode = createNode(data);
    if (*root == NULL) {
        newNode->color = 1; // Root is always black
        *root = newNode;
    } else {
        Node *parent = NULL;
        Node *current = *root;
        while (current != NULL) {
            parent = current;
            if (newNode->data < current->data) current = current->left;
            else current = current->right;
        }
        newNode->parent = parent;
        if (newNode->data < parent->data) parent->left = newNode;
        else parent->right = newNode;
        fixViolation(root, newNode);
    }
}
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 15);
    printf("Inorder Traversal: ");
    inorder(root);
    return 0;
}
