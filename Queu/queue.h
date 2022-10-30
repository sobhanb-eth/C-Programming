//SOBHAN BAHRAMI - EDNQOR - ASSIGNMENT 6
#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

/*NOTE TO SLEF: dear me, remember that decleration, definition and Initialization are all different! if you do not assign anything to 
the <type of object>  you have "declared", then it is not initialized. PLEASE REMEMBER THIS. if not ******READ THIS FIRST******
*/

/* Structs declarations */
typedef struct Node {
    int value;
    struct Node* next;  /* pointer to the next Node */
} Node;
typedef struct Queue {
    Node* front;  /* pointer to the beginning of the queue */
    Node* back;   /* pointer to the end of the queue */
} Queue;

// --------------- { Declaration (reference - prototype) of Functions } -------------------
void initialize(Queue* queue);
void enqueue(Queue* queue, int value);
void dequeue(Queue* queue);
void empty(Queue* queue);
bool isEmpty(Queue* queue);
int front(Queue* queue);
int back(Queue* queue);
int length(Queue* queue);
void display(Queue* queue);

#endif

