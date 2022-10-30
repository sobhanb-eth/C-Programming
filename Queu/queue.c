//SOBHAN BAHRAMI
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// --------------- { Implementation of Functions } -------------------
/* 
- initialize: Gets a pointer to a Queue and initializes "front" and "back" pointers to NULL.
*/
void initialize(Queue* queue)
{
    queue->front = NULL;
    queue->back = NULL;
}

/* - enqueue: Appends a new Node to the end of the list. Make sure to set "front" and "back" pointers accirdingly,
  especially when the list was empty earlier.
*/
void enqueue(Queue* queue, int value)
{
    Node* newNode;
    /* allocate a new node on the heap (dynamically) */
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Error: ");
        free (newNode);
        empty(queue);
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL; // initialize the next node with null
    /* Append a new node to the end of the list */
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->back = newNode;
    }
    else
    {
        queue->back->next = newNode;
        queue->back = newNode;
    }
}

/* - dequeue: Removes the first element of a queue given as parameter and sets "front" pointer to the next element.
 Don't forget setting "back" pointer to NULL if the list is empty.
*/
void dequeue(Queue* queue)
{
    Node* frontNode;
    if (!isEmpty(queue))
    {
        frontNode = queue->front;
        queue->front = frontNode->next;
        if (queue->front == NULL)
        {
            queue->back = NULL;//if list is empty set back pointer to null
        }
        /* free space allocated by the initial front node */
        free(frontNode);
    }
}

/*  empty: Removes all elements from a given Queue. */
void empty(Queue* queue)
{
    Node* tempNode;
    while (queue->front != NULL)
    {
        tempNode = queue->front;
        queue->front = queue->front->next;
        free(tempNode);
    }
    queue->back = NULL;
}

/* - isEmpty: Returns true if the Queue in parameter is empty. (Hint: the queue is empty if its "front" and "back" pointers are NULL. */
bool isEmpty(Queue* queue)
{
    return queue->front == NULL && queue->back == NULL;
}

/* - front : Returns the value of first and last elements respectively. In case the list is empty, these functions return -1. */
int front(Queue* queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    return queue->front->value;
}

/* - back: Returns the value of first and last elements respectively. In case the list is empty, these functions return -1. */
int back(Queue* queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    return queue->back->value;
}

/*  - length: Returns the length of the queue. */
int length(Queue* queue)
{
    int len = 0;
    Node* currentNode = queue->front;
    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        len++;
    }
    return len;
}

/* - display: Lists all values of the list. In case the queue is empty, print "The queue is empty!" message to the standard output.
 Otherwise the output format in case of element (10, 20, 30) is "10 -> 20 -> 30 -> nil".
*/
void display(Queue* queue)
{
    Node* currentNode = queue->front;
    if (isEmpty(queue))
    {
        printf("The queue is empty!\n");
    }
    else
    {
        while (currentNode != NULL)
        {
            printf("%d -> ", currentNode->value);
            currentNode = currentNode->next;
        }
        printf("nil\n");
    }
}
//auxillary deallocation function.
void deallocate(struct Node* node) {
    free (node);
}