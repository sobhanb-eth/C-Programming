# C- dynamic memory handling - Person Database
dynamic memory handling.

It also contains some optional tasks:

3 points for the base tasks
 1-2 extra points can be given for the advanced parts 
 

1. Person data should be stored in heap memory. So write a program which handles addition, listing (and deletion optionally).
- Person name is stored in a char[30].
- Advanced task (+1 point): use a struct in which you store the name, age, and job (char[30], unsigned, char[30] respectively).
- Hint: struct is a container which can be declared like this:

struct Person
{
char name[30];
unsigned int age;
char job[30];
};

Members can be accessed by "." operator, e.g. pers.name. Or having a pointer on persons: (*p).name or p->name.

2. The program runs for as long as possible. It reads menu items from standard input:
- a: Add a new person to the database. After hitting this menu item, the program queries for the data above.
- l: List the whole database.
- x: Exit from the program.
- d: (advanced): Delete person from the database. It queries for a name and deletes that (or the corresponding struct).

3. Memory should be allocated dynamically for persons since we don't even know how big the database will be.

4. There should be a global array (hereinafter named "iterator") of pointers in which the pointers pointing to persons are stored. We'll iterate over this array and find or list the elements of the database. If the database stores names only, then its type is char**.
- The global array is allocated on the heap at the beginning of the program. Its initial size is 10, but in the case of more persons, its size is incremented by 5 every time when there is no more place for the next person. (For example when adding the 11th person the array size increments to 15 and when adding the 16th person it increments to 20, etc.)
- A person can be accessed as iterator[i] through a pointer to this person (since persons are also allocated in the heap).
- (advanced) If the number of persons is decreased by 6 using deletion operation, then the "iterator" array size should also be decreased by 5. 

5. Create two more global variables:
- Size of the database (size) which should also be changed by "add" and "delete" operations. This is the actual size of the array.
- Current number of added persons (count) determines the upper limit of the possible array index.

6. Exiting, person addition, and database listing (and optionally deletion) should be handled in separate functions.

 

7. In case a user enters a wrong letter in the menu or enters a name longer than 30 characters then an error message should be printed.

 

8. Don't forget the deallocation of dynamic memory (even in case of user errors). It is worth creating a function for deallocation which can be called when some error happens or the user exits.

 

9. Important: The program should print nothing but the error message in step 7.