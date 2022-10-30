# C-Queue
-----

The task is the implementation of a queue data structure with linked list. 
Queue is a FIFO (first in, first out) data structure which means
that elements can be removed in the order of insertion. In other words: 
elements are inserted to the end and removed from the beginning.

In the implementation let's define the following structs:

Node (members of the queue)
  - value: Stores an integer.
  - next: Pointer to the next Node.
Queue
  - front: Pointer to the beginning of the queue.
  - back: Pointer to the end of the queue.

The solution is similar to the implementation of "stack" of 12th practice class, but this time every operation gets a pointer to a Queue.

Operations
----------

Let's define the following queue operations:

Modifier operations
  - initialize: Gets a pointer to a Queue and initializes "front" and "back" pointers to NULL.
  - enqueue: Appends a new Node to the end of the list. Make sure to set "front" and "back" pointers accirdingly, especially when the list was empty earlier.
  - dequeue: Removes the first element of a queue given as parameter and sets "front" pointer to the next element. Don't forget setting "back" pointer to NULL if the list is empty.
  - empty: Removes all elements from a given Queue.

Non-modifier operations:
  - isEmpty: Returns true if the Queue in parameter is empty. (Hint: the queue is empty if its "front" and "back" pointers are NULL.
  - front & back: Returns the value of first and last elements respectively. In case the list is empty, these functions return -1.
  - length: Returns the length of the queue.
  - display: Lists all values of the list. In case the queue is empty, print "The queue is empty!" message to the standard output. Otherwise the output format in case of element (10, 20, 30) is "10 -> 20 -> 30 -> nil".

Requirements
------------
  - The program should be separated to multiple source files:
    - main.c which contains only main() function. This file is provided to you with some built-in test code.
    - queue.h header which contains the definition of struct Queue, the declaration of struct Node and all function declarations. The header file should contain header guards.
    - queue.c Contains the definition of functions and struct Node.
  - main.c should be handed without modification.
  - Don't forget checking emptiness of the queue in the operations when necessary.