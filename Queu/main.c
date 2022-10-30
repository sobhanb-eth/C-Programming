//SOBHAN BAHRAMI
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

/*
    Correct output of this program:
    
    10 -> 20 -> nil
    10 -> 20 -> 30 -> nil
    Number of elements: 3.
    20 -> 30 -> nil
    Number of elements 2.
    The queue is empty.
*/

int main()
{
    Queue list;
    initialize(&list);
    if (!isEmpty(&list))
    {
        fprintf(stderr, "Error!\n");
    }

    enqueue(&list, 10);
    enqueue(&list, 20);
    display(&list);       // Output: 10 -> 20 -> nil

    if (front(&list) != 10)
    {
        fprintf(stderr, "Error!\n");
    }
    
    if (back(&list) != 20)
    {
        fprintf(stderr, "Error!\n");
    }

    enqueue(&list, 30);
    display(&list);       // Output: 10 -> 20 -> 30 -> nil

    int l = length(&list);
    if (l == 3)
    {
        fprintf(stdout, "Number of elements: %d.\n", l);
    }
    else
    {
        fprintf(stderr, "Error!\n");
    }
    
    dequeue(&list);
    display(&list);     // Output: 20 -> 30 -> nil

    if (front(&list) != 20)
    {
        fprintf(stderr, "Error!\n");
    }
    
    if (back(&list) != 30)
    {
        fprintf(stderr, "Error!\n");
    }

    l = length(&list);
    if (l == 2)
    {
        fprintf(stdout, "Number of elements: %d.\n", l);
    }
    else
    {
        fprintf(stderr, "Error!\n");
    }

    empty(&list);
    display(&list);    // Output: The queue is empty.
    return 0;
}
