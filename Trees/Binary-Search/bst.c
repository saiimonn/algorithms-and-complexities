#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} *BST;

void insert(BST *, int);
void delete(BST *, int);
int search(BST, int);
void inorder(BST);

int main() {
    BST root = NULL;
    
    insert(&root, 50);
    insert(&root, 47);
    insert(&root, 10);
    insert(&root, 67);
    insert(&root, 83);
    
    inorder(root);
}

void insert(BST *root, int data) {
    BST *curr;
    
    for(curr = root; *curr != NULL;) {
        curr = (data > (*curr)->data) ? &(*curr)->right : &(*curr)->left;
    }
    
    *curr = (BST)malloc(sizeof(struct node));
    (*curr)->data = data;
    (*curr)->left = NULL;
    (*curr)->right = NULL;
}

void delete(BST *root, int data) {
    BST *curr;
    
    for(curr = root; *curr != NULL && (*curr)->data != data;) {
        curr = (data > (*curr)->data) ? &(*curr)->right : &(*curr)->left;
    }
    
    if(*curr != NULL) {
        BST target = *curr;
        
        if(target->right != NULL && target->left != NULL) {
            BST *trav = &target->right;
            while((*trav)->left != NULL) {
                trav = &(*trav)->left;
            }
            
            target->data = (*trav)->data;
            
            target = *trav;
            *trav = target->right;
        } else {
            *curr = (target->left != NULL) ? target->left : target->right;
        }
        free(target);
    }
}

int search(BST root, int data) {
    BST trav;
    for(trav = root; trav != NULL && trav->data != data;) {
        trav = (data > trav->data) ? trav->right: trav->left;
    }
    
    return (trav != NULL) ? 1 : 0;
}

void inorder(BST root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}