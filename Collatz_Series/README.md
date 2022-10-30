# C- Collatz
Create a program, which calculates the length of the Collatz series starting from a user-defined integer.

The first element of the Collatz series is an arbitrary positive integer. Following elements could be defined recursively: the next element is 3 times the previous element increased by one, if the previous element was odd, otherwise the next element is the half of the previous element.

As an example, starting from 3 as an input, the elements of the Collatz series are

3, 10, 5, 16, 8, 4, 2, 1

According to the Collatz conjecture, this series **always** reaches 1, which is the last element in the previous
example, making the length of the Collatz series 8.

The program prompts for the first element of the series as an input. The terminal should output the Collatz series (as
in the example above), and the length of the series in the next line. The program should output nothing else to the
terminal.
