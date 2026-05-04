#include <stdio.h>
#include <stdlib.h>

#define T 3  // Minimum degree (change this if needed)

// B-Tree Node
typedef struct BTreeNode {
    int *keys;              // array of keys
    struct BTreeNode **C;   // child pointers
    int n;                  // current number of keys
    int leaf;               // is leaf node
} BTreeNode;

// Create a new node
BTreeNode* createNode(int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->keys = (int*)malloc((2*T - 1) * sizeof(int));
    node->C = (BTreeNode**)malloc((2*T) * sizeof(BTreeNode*));
    node->n = 0;
    return node;
}

// Traverse the tree
void traverse(BTreeNode* root) {
    if (root == NULL) return;

    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->C[i]);
        printf("%d ", root->keys[i]);
    }

    if (!root->leaf)
        traverse(root->C[i]);
}

// Split child
void splitChild(BTreeNode* parent, int i, BTreeNode* fullChild) {
    BTreeNode* newNode = createNode(fullChild->leaf);
    newNode->n = T - 1;

    // Copy last (T-1) keys
    for (int j = 0; j < T - 1; j++)
        newNode->keys[j] = fullChild->keys[j + T];

    // Copy children if not leaf
    if (!fullChild->leaf) {
        for (int j = 0; j < T; j++)
            newNode->C[j] = fullChild->C[j + T];
    }

    fullChild->n = T - 1;

    // Shift parent's children
    for (int j = parent->n; j >= i + 1; j--)
        parent->C[j + 1] = parent->C[j];

    parent->C[i + 1] = newNode;

    // Shift parent's keys
    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = fullChild->keys[T - 1];
    parent->n += 1;
}

// Insert into non-full node
void insertNonFull(BTreeNode* node, int k) {
    int i = node->n - 1;

    if (node->leaf) {
        // Insert into leaf
        while (i >= 0 && node->keys[i] > k) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = k;
        node->n += 1;
    } else {
        while (i >= 0 && node->keys[i] > k)
            i--;

        i++;

        if (node->C[i]->n == 2*T - 1) {
            splitChild(node, i, node->C[i]);

            if (node->keys[i] < k)
                i++;
        }

        insertNonFull(node->C[i], k);
    }
}

// Insert function
BTreeNode* insert(BTreeNode* root, int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2*T - 1) {
        BTreeNode* newRoot = createNode(0);
        newRoot->C[0] = root;

        splitChild(newRoot, 0, root);

        int i = 0;
        if (newRoot->keys[0] < k)
            i++;

        insertNonFull(newRoot->C[i], k);

        return newRoot;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

// Driver code
int main() {
    BTreeNode* root = NULL;

    int values[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Traversal of B-Tree:\n");
    traverse(root);

    return 0;
}