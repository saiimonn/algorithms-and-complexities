#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
} *AVL;

int max(int, int);
int getHeight(AVL);
int getNewHeight(AVL);
int getBalanceFactor(AVL);

void rotateLeft(AVL *);
void rotateLeft(AVL *);

void balance(AVL *);

void insert(AVL *, int);
void delete(AVL *, int);
bool search(AVL, int);
void preorder(AVL);

int main() {
    AVL root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Search for 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    printf("Search for 90: %s\n", search(root, 90) ? "Found" : "Not Found");

    delete(&root, 20);
    printf("Preorder traversal after deleting 20: ");
    preorder(root);
    printf("\n");

    delete(&root, 30);
    printf("Preorder traversal after deleting 30: ");
    preorder(root);
    printf("\n");

    delete(&root, 50);
    printf("Preorder traversal after deleting 50: ");
    preorder(root);
    printf("\n");

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(AVL x) {
    return x == NULL ? 0 : x->height;
}

int getNewHeight(AVL x) {
    return max(getHeight(x->left), getHeight(x->right));
}

int getBalanceFactor(AVL x) {
    return x == NULL ? 0 : getHeight(x->left) - getHeight(x->right);
}

void rotateLeft(AVL *x) {
    AVL temp = (*x)->right;

    (*x)->right = temp->left;
    temp->left = *x;

    (*x)->height = getNewHeight(*x);
    temp->height = getNewHeight(temp);

    *x = temp;
}

void rotateRight(AVL *x) {
    AVL temp = (*x)->left;

    (*x)->left = temp->right;
    temp->right = *x;

    (*x)->height = getNewHeight(*x);
    temp->height = getNewHeight(temp);

    *x = temp;
}

void balance(AVL *root) {
    if (*root != NULL) {
        int balanceFactor = getBalanceFactor(*root);

        //case 1: LL imbalance
        if (balanceFactor > 1 && getBalanceFactor((*root)->left) > 0) {
            rotateRight(root);
        }

        //case 2: LR imbalance
        else if (balanceFactor > 1) {
            rotateLeft(&(*root)->left);
            rotateRight(root);
        }

        //case 3: RR imbalance
        else if (balanceFactor < -1 && getBalanceFactor((*root)->right) < 0) {
            rotateLeft(root);
        }

        //case 4: RL imbalance
        else if (balanceFactor < -1) {
            rotateRight(&(*root)->right);
            rotateLeft(root);
        }
    }
}

void insert(AVL *root, int data) {
    if (*root == NULL) {
        AVL newNode = (AVL)malloc(sizeof(struct node));

        if (newNode != NULL) {
            newNode->data = data;
            newNode->left = newNode->right = NULL;
            *root = newNode;
        }
    }

    else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    }

    else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }

    (*root)->height = getNewHeight(*root);

    balance(root);
}

void delete(AVL *root, int data) {
    if (*root == NULL) {
        return;
    }

    if (data < (*root)->data) {
        delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete(&(*root)->right, data);
    } else {
        if ((*root)->right == NULL) {
            AVL temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            AVL temp = (*root)->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->data = temp->data;
            delete(&(*root)->right, temp->data);
        }
    }

    if (*root != NULL) {
        (*root)->height = getNewHeight(*root);
    }

    balance(root);
}

bool search(AVL root, int data) {
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        return true;
    }

    return search((data < root->data) ? root->left : root->right, data);
}

void preorder(AVL root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}