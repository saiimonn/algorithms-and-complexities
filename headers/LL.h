#include <stdio.h>
#include <stdlib.h>

#ifndef LL_H
#define LL_H

typedef struct node {
    int data;
    struct node *link;
} *Node;

void printLL(Node list) {
    printf("\n");
    for(; list != NULL; list = list->link) {
        printf(" %d -> ", list->data);
    }
    printf("NULL\n");
}

void insertLast(Node *list, int data) {
    Node temp = (Node)malloc(sizeof(Node));
    
    if(temp != NULL) {
        Node *trav;
        for(trav = list; (*trav) != NULL; trav = &(*trav)->link) {}
        
        temp->data = data;
        temp->link = NULL;
        (*trav)->link = temp;
    }
}

void insertSorted(Node *list, int data) {
    Node temp = (Node) malloc(sizeof(Node));
    
    if (temp != NULL) {
        Node *trav;
        for(trav = list; (*trav) != NULL && (*trav)->data <= data; trav = &(*trav)->link) {}
        
        temp->data = data;
        temp->link = *trav;
        *trav = temp;
    }
}

void deleteFirst(Node *list) {
    if (list != NULL) {
        Node temp = *list;
        *list = (*list)->link;
        free(temp);
    }
}

#endif