#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int UNT;

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

// --------------- { SOBHAN BAHRAMI - EDNQOR - Imperative Programming (C) Assignment 4 } -------------------

// --------------- { Function Prototype } -------------------
void deallocHEAP();
// --------------- { # END # } -------------------

// --------------- { Structs } -------------------
typedef struct
{
    UNT age;
    char name[30];
    char job[30];
} Person;

// --------------- { # END # } -------------------

// --------------- { Global Variables } -------------------
UNT count = 0;
UNT size = 10;
UNT delcount = 0;
Person **iterator;

// --------------- { # END G-VARS # } -------------------

// --------------- { Utility Functions - Sub-Programs } -------------------
int isValidMenuOption(char c)
{
    if ((c == 'a' || c == 'l' || c == 'd' || c == 'x') || (c == 'A' || c == 'L' || c == 'D' || c == 'X'))
    {
        return 1;
    }
    return 0;
}
int validateEntry(char *str)
{

    //printf("string to be validated: %s", str);
    if (strlen(str) > 30 || strlen(str) < 1)
    {
        //getchar();
        return 1;
    }
    //getchar();
    return 0;
}
void spacer()
{
    for (int i = 1; i < 50; i++)
    {
        printf(" ");
    }
}

void allocateMemory()
{
    //dynamically allocate memory for the Iterator a.k.a DB on HEAP
    iterator = malloc(sizeof(Person) * size);
    for (UNT i = 0; i < size; i++)
    {
        iterator[i] = NULL;
    }
    printf("Size: %u, Count: %u, deleted count: %u\n", size, count, delcount);
}

void reallocateMemory()
{
    iterator = realloc(iterator, sizeof(Person) * size);
    printf("Size: %u, Count: %u, deleted count: %u\n", size, count, delcount);
}

//access the iterator a.k.a DB and reallocate some memory to insert new person
void AddPersonToDB()
{
    // in the case of more persons, its size is incremented by 5
    //every time when there is no more place for the next person.
    if (count != 0 && count != 5 && count % 5 == 0)
    {
        size = size + 5;
        reallocateMemory();
    }
    iterator[count] = malloc(sizeof(Person));
    if (iterator == NULL)
    {
        printf(RED "MEMORY ALLOCATION FAILED! - CAN NOT ADD NEW PERSON" RESET);
        return;
    }
    else
    {

        char n[30];
        UNT age;
        char j[30];
        UNT flagn = 0;
        UNT flagj = 0;
        int not_pass = 0;
        printf("Please enter the Name:\n");
        scanf("%s", n);
        not_pass = validateEntry(n);
        if (not_pass)
        {
            printf("\nName should be 30 characters.\n");
            deallocHEAP();
            printf("Dealocating everything...Avoiding Memory Leak and Stack Smash ...\n");
            printf("Program Terminated!\n");
            exit(1);
            return;
        }
        else
        {
            printf("Please enter the Age:\n");
            scanf("%u", &age);
            printf("Please enter the Job:\n");
            scanf("%s", j);
            not_pass = validateEntry(j);
            if (not_pass)
            {
                age = 0;
                printf("\nJob should be 30 characters.\n");
                deallocHEAP();
                printf("Dealocating everything...Avoiding Memory Leak and Stack Smash ...\n");
                printf("Program Terminated!\n");
                exit(1);
                return;
            }
            else
            {
                strcpy(iterator[count]->name, n); //string assignment in c is via copy by this function
                flagn = 1;
                strcpy(iterator[count]->job, j);
                flagj = 1;
                if (flagn && flagj)
                {
                    iterator[count]->age = age;
                    count++;
                    printf(GRN "\n---Person Added Successfully---\n\n" RESET);
                }
                else
                {
                    printf("something went wrong! please try again.\n");
                }
            }
        }
    }
}

//List all the elements inside DB -- hence it is global, no need to give it as parameter
void listDataBase()
{
    printf("Size: %u, Count: %u, deleted count: %u\n", size, count, delcount);
    if (count == 0)
    {
        printf(WHT "\nDatabase is Empty!\n\n" RESET);
        return;
    }
    for (UNT i = 0; i < count; i++)
    {
        //Person* current_person = iterator[i];
        printf(WHT "\nPerson #%u\n" RESET, i + 1);
        printf(CYN "Name: " RESET);
        printf(BLU "%s, " RESET, iterator[i]->name);
        printf(CYN "Age: " RESET);
        printf(BLU "%u, " RESET, iterator[i]->age);
        printf(CYN "Job: " RESET);
        printf(BLU "%s " RESET, iterator[i]->job);
    }
    printf(GRN "\n\n---Everything Listed!---\n\n");
}

//remove a person from DB
void removePerson()
{
    char name_to_search[30];
    UNT match = 0;
    UNT i = 0;
    printf(RED "\nPlease type the NAME of the person that you want to remove: " RESET);
    scanf("%s", name_to_search);
    for (i = 0; i < count; i++)
    {
        //if both strings match strcmp returns 0
        if (strcmp(name_to_search, iterator[i]->name) == 0)
        {
            free(iterator[i]);
            iterator[i] = NULL;
            match = i;
            printf("\n---Record found, person %u REMOVED---\n", match + 1);
            break;
        }
    }
    if ((i != 0 && match == 0) || count == 0)
    {
        printf(RED "\n\nNO RECORDS FOUND!\n\n" RESET);
        return;
    }
    else
    {
        count = count - 1;
    }

    // (advanced) If the number of persons is decreased by 6 using deletion
    // operation, then the "iterator" array size should also be decreased by 5.
    delcount++;
    if ((count % 5 == 0 && count != 0 && count != 5 && count != 10) || delcount == 6)
    {
        printf("Size: %u, Count: %u, deleted count: %u\n", size, count, delcount);
        delcount = 0;
        size -= 5;
        reallocateMemory();
    }
    //TRICKY PART! if we don't copy the elements over to and back from
    //iterator, will result in seg fault for listing! -- data corruption
    //allocate a temprorary DB copy everything to there except the deleted person
    //MATCH index, free the iterator
    //copy back everything to the iterator;
    Person **temp_db = malloc(sizeof(Person) * size);
    // for (UNT i = 0; i < count; i++)
    // {
    //     if (i == match)
    //     {
    //         i++;
    //         temp_db[i - 1] = iterator[i];
    //         iterator[i] = 0;
    //     }
    //     else
    //     {
    //         temp_db[i] = iterator[i];
    //         iterator[i] = 0;
    //     }
    // }

    for (unsigned int i = 0, k = 0; i < count; i++, k++)
    {
        if (i == match)
        {
            k++;
        }
        temp_db[i] = iterator[k];
        iterator[k] = 0;
    }

    free(iterator);
    iterator = temp_db;
    temp_db = 0;
}

void deallocHEAP()
{
    for (UNT i = 0; i < size; i++)
    {
        if (iterator[i] != NULL)
        {
            free(iterator[i]);
            iterator[i] = NULL;
        }
    }
    free(iterator);
    iterator = 0;
}
// --------------- { # END Sub-Progs # } -------------------

int main()
{
    allocateMemory();
    //control flow - main loop
    int init = 1;

    char menu_option;
    int menu_input_flow = 0;
    int cnt = 1;
    while (init)
    {
        spacer();
        printf(YEL "-> a: Add a new person to the database.\n" RESET);
        spacer();
        printf(CYN "-> l: List the whole database.\n" RESET);
        spacer();
        printf(RED "-> d: Delete person from the database.\n" RESET);
        spacer();
        printf("-> x: Exit the program.\n\n");

        do
        {
            printf(MAG "\nTimes Loop Executed: %d\n\n" RESET, cnt);
            cnt++;
            menu_input_flow = 0;
            printf(WHT "Choose an option for the Menu:  " RESET);
            scanf("%c", &menu_option);
            //getchar();
            if (isValidMenuOption(menu_option) == 1)
            {
                menu_input_flow = 0;

                switch (menu_option)
                {
                case 'a':
                    AddPersonToDB();
                    break;
                case 'A':
                    AddPersonToDB();
                    break;
                case 'l':
                    printf("Retrieving Records...\n");
                    listDataBase();
                    break;
                case 'L':
                    printf("Retrieving Records...\n");
                    listDataBase();
                    break;
                case 'd':
                    removePerson();
                    break;
                case 'D':
                    removePerson();
                    break;
                case 'x':
                    printf("Program Terminated by user!\n");
                    deallocHEAP();
                    if (iterator == NULL)
                    {
                        printf("HEAP CLEARED - MEMORY DEALLOCATED!\n");
                    }
                    else
                    {
                        printf("DEALLOCATION FAILED!\n");
                    }
                    return 0;
                case 'X':
                    deallocHEAP();
                    if (iterator == NULL)
                    {
                        printf("HEAP CLEARED - MEMORY DEALLOCATED!\n");
                    }
                    else
                    {
                        printf("DEALLOCATION FAILED!\n");
                    }
                    return 0;
                default:
                    break;
                    printf("Bro something went wrong!\n");
                }
            }
            else
            {
                printf("-/-/-/-/-/-/Wrong Input! Try again-\\-\\-\\-\\-\\-\\\n");
                //printf("\n pressed key:  %c \n",menu_option);
                scanf("%c", &menu_option);
                menu_input_flow = 1;
            }
        } while (menu_input_flow);
        getchar(); //flushes the (input)buffer stream.
    }

    return 0;
}