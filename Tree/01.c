// BT Traversal

// Binary Tree Implementation
// using Recursion here

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left, *right;
};

struct node* create() {
    int x;
    struct node* newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data(-1 for No node) : ");
    scanf("%d", &x);

    if(x == -1) {
        return 0;       // Successfully executed the above function
    } else { 

    newnode->data = x;
    printf("Enter left child of %d : \n", x);
    newnode->left = create();

    printf("Enter right child of %d : \n", x);
    newnode->right = create();

    return newnode;}
    
}

void preorder(struct node* root) {
    if(root == 0) {
        return;     // Exit the function without returning any value
    } else {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if(root == 0) {
        return;
    } else {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if(root == 0) {
        return;
    } else {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root;
    root = 0;
    root = create();

    printf("Preorder is : ");
    preorder(root);
    printf("\n");

    printf("Inorder is : ");
    inorder(root);
    printf("\n");

    printf("Postorder is : ");
    postorder(root);
    printf("\n");

    return 0;
}