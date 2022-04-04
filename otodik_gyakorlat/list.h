#ifndef LinkedList_H
#define LinekdList_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *n) {
    while (n != NULL) { ;
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

#endif 