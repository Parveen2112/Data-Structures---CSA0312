#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *left, *right;
};
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
struct Node* rightRotate(struct Node* root) {
    struct Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}
struct Node* leftRotate(struct Node* root) {
    struct Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}
struct Node* splay(struct Node* root, int key) {
    if (root == NULL || root->key == key) return root;

    if (key < root->key) {
        if (root->left == NULL) return root;
        if (key < root->left->key) {
            root->left = splay(root->left, key);
            root = rightRotate(root);
        } else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if (root->right == NULL) return root;
        if (key > root->right->key) {
            root->right = splay(root->right, key);
            root = leftRotate(root);
        } else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    root = splay(root, key);
    if (root->key == key) return root;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }
    return newNode;
}
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    printf("Preorder traversal of the modified Splay tree is: ");
    preOrder(root);
    return 0;
}
