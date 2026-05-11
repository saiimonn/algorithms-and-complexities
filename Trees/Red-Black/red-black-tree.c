#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED 0
#define BLACK 1

typedef struct node {
    int data;
    struct node *parent;
    struct node *left;
    struct node *right;
    int color;
} *RBT;

void rotateLeft(RBT);
void rotateRight(RBT);

void insert(RBT *, int);
void delete(RBT *, int);
void deleteFixup(RBT *, RBT);

void preorder(RBT);

int main() {
    
}

void rotateLeft(RBT x) {
    RBT temp = x->right;

    x->right = temp->left;
    if (temp->left != NULL) {
        temp->left->parent = x;
    }

    temp->left = x;
    temp->parent = x->parent;

    if (x->parent != NULL) {
        if (x == x->parent->left) {
            x->parent->left = temp;
        } else {
            x->parent->right = temp;
        }
    }

    x->parent = temp;
}

void rotateRight(RBT x) {
    RBT temp = x->left;

    x->left = temp->right;
    if (temp->right != NULL) {
        temp->right->parent = x;
    }

    temp->right = x;
    temp->parent = x->parent;

    if (x->parent != NULL) {
        if (x == x->parent->left) {
            x->parent->left = temp;
        } else {
            x->parent->right = temp;
        }
    }

    x->parent = temp;
}

void insert(RBT *root, int data) {
    RBT *trav = root, nodeParent = NULL;

    // traversal
    while (*trav != NULL && (*trav)->data != data) {
        nodeParent = *trav;

        if (data < (*trav)->data) {
            trav = &(*trav)->left;
        } else {
            trav = &(*trav)->right;
        }
    }

    if (*trav != NULL) return;

    RBT temp = (RBT)malloc(sizeof(struct node));

    temp->data = data;
    temp->parent = nodeParent;
    temp->left = NULL;
    temp->right = NULL;
    temp->color = RED;

    *trav = temp;

    // fix tree
    RBT node = temp;
    while (nodeParent != NULL && nodeParent->color == RED && nodeParent->parent != NULL) {
        bool parentIsLeft = (nodeParent == nodeParent->parent->left) ? true : false;
        bool nodeIsLeft = (node == nodeParent->left) ? true : false;
        RBT uncle = (parentIsLeft) ? nodeParent->parent->right : nodeParent->parent->left;


        // case: uncle is red
        if (uncle != NULL && uncle->color == RED) {
            nodeParent->color = BLACK;
            uncle->color = BLACK;

            nodeParent->parent->color = RED;
        } else {
            nodeParent->color = BLACK;
            nodeParent->parent->color = RED;

            if (parentIsLeft) {

                // case: uncle is black triangle
                if (!nodeIsLeft) {
                    rotateLeft(nodeParent);
                    nodeParent = node;
                }

                rotateRight(nodeParent->parent);
                nodeParent = nodeParent->right;

                
            } else {
                if (nodeIsLeft) {
                    rotateRight(nodeParent);
                    nodeParent = node;
                }

                rotateLeft(nodeParent->parent);
                nodeParent = nodeParent->left;
            }
        }

        node = nodeParent;
        nodeParent = nodeParent->parent;
    }

    if (nodeParent != NULL && nodeParent->parent == NULL) {
        *root = nodeParent;
    }

    (*root)->color = BLACK;
}

void transplant(RBT *root, RBT toBeDeleted, RBT replacement) {
    if (toBeDeleted == *root) {
        *root = replacement;
    } else if (toBeDeleted->parent->left == toBeDeleted) {
        toBeDeleted->parent->left = replacement;
    } else {
        toBeDeleted->parent->right = replacement;
    }
}

void delete(RBT *root, int data) {
    RBT *trav = root
}