#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 5
#define P 0.5

typedef struct node {
    int value;
    int level;
    struct node *forward[MAX_LEVEL + 1];
} *Node;

typedef struct {
    int level;
    Node header;
} SkipList;

/* Create Node */
Node createNode(int value, int level) {

    Node newNode = (Node)malloc(sizeof(struct node));

    newNode->value = value;
    newNode->level = level;

    for (int i = 0; i <= MAX_LEVEL; i++) {
        newNode->forward[i] = NULL;
    }

    return newNode;
}

/* Create Skip List */
SkipList *createSkipList() {

    SkipList *list = (SkipList *)malloc(sizeof(SkipList));

    list->level = 0;

    list->header = createNode(-1, MAX_LEVEL);

    return list;
}

/* Random Level */
int randomLevel() {

    int level = 0;

    while (((double)rand() / RAND_MAX) < P &&
           level < MAX_LEVEL) {
        level++;
    }

    return level;
}

/* Insert */
void insert(SkipList *list, int value) {

    Node update[MAX_LEVEL + 1];
    Node current = list->header;

    // Find insertion position
    for (int i = list->level; i >= 0; i--) {

        while (current->forward[i] != NULL &&
               current->forward[i]->value < value) {

            current = current->forward[i];
        }

        update[i] = current;
    }

    current = current->forward[0];

    // Avoid duplicates
    if (current == NULL || current->value != value) {

        int rlevel = randomLevel();

        // Increase list level
        if (rlevel > list->level) {

            for (int i = list->level + 1; i <= rlevel; i++) {
                update[i] = list->header;
            }

            list->level = rlevel;
        }

        Node newNode = createNode(value, rlevel);

        // Reconnect pointers
        for (int i = 0; i <= rlevel; i++) {

            newNode->forward[i] = update[i]->forward[i];

            update[i]->forward[i] = newNode;
        }

        printf("%d inserted\n", value);
    }
}

/* Search */
int search(SkipList *list, int value) {

    Node current = list->header;

    for (int i = list->level; i >= 0; i--) {

        while (current->forward[i] != NULL &&
               current->forward[i]->value < value) {

            current = current->forward[i];
        }
    }

    current = current->forward[0];

    if (current != NULL &&
        current->value == value) {
        return 1;
    }

    return 0;
}

/* Delete */
void deleteNode(SkipList *list, int value) {

    Node update[MAX_LEVEL + 1];
    Node current = list->header;

    for (int i = list->level; i >= 0; i--) {

        while (current->forward[i] != NULL &&
               current->forward[i]->value < value) {

            current = current->forward[i];
        }

        update[i] = current;
    }

    current = current->forward[0];

    if (current != NULL &&
        current->value == value) {

        for (int i = 0; i <= list->level; i++) {

            if (update[i]->forward[i] != current)
                break;

            update[i]->forward[i] = current->forward[i];
        }

        free(current);

        // Adjust levels
        while (list->level > 0 &&
               list->header->forward[list->level] == NULL) {

            list->level--;
        }

        printf("%d deleted\n", value);
    }
    else {
        printf("%d not found\n", value);
    }
}

/* Display */
void display(SkipList *list) {

    printf("\n===== SKIP LIST =====\n");

    for (int i = list->level; i >= 0; i--) {

        Node node = list->header->forward[i];

        printf("Level %d: ", i);

        while (node != NULL) {

            printf("%d ", node->value);

            node = node->forward[i];
        }

        printf("\n");
    }
}

/* Main */
int main() {

    srand(time(NULL));

    SkipList *list = createSkipList();

    insert(list, 10);
    insert(list, 20);
    insert(list, 30);
    insert(list, 15);
    insert(list, 25);

    display(list);

    printf("\nSearching 15...\n");

    if (search(list, 15))
        printf("15 found\n");
    else
        printf("15 not found\n");

    deleteNode(list, 20);

    display(list);

    return 0;
}