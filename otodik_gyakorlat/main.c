//Cerdits: https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
//https://www.geeksforgeeks.org/linked-list-set-1-introduction/
//https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//w3schools
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "array.h"
#include "queue.h"
#include "stack.h"

int main(){

    printf("Lancolt lista:\n");

    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2; 
    second->next = third;

    third->data = 3; 
    third->next = NULL;

    printList(head);

    printf("Dinamikus tomb:\n");
    Array a;
    int i;

    initArray(&a, 5);  
    for (i = 0; i < 100; i++){
        insertArray(&a, i);  
    }
        
    printf("%d\n", a.array[9]);  
    printf("%d\n", a.used);  
    freeArray(&a);

    printf("QUEUE:\n");

    struct Queue *queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    printf("Stack: \n");
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
    
    return 0;
}