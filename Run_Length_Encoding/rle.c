//SOBHAN BAHRAMI - EDNQOR - ASSIGNMENT 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UNT;
typedef struct Pair
{
    char c; //encoded character
    UNT n;  //number of consecutive occurrences of `c`
} Pair;

typedef struct Encoded
{
    UNT length; // a positive integer which indicates how many elements the encoded result contains
    Pair *arr;  //a dynamic array of `length` elements that contain pointers to `Pair` objects
} Encoded;

UNT size = 0;
UNT indx = 0;

Pair *pairs;
Encoded *e_result;
char *d_result;
//Pair pairs[255];

// --------------- { Utility Functions - Sub-Programs' Prototypes } -------------------
int validateEntry(char *str)
{
    UNT i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < 'a' || str[i] > 'z')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
//void allocateMemory();
void deallocHEAP()
{   
    free(pairs);
    pairs = 0;
    free(e_result);
    e_result = 0;
    free(d_result);
    d_result = 0;
}

Encoded *encode(char *text)
{
    UNT len_of_input = strlen(text);
    size = len_of_input;
    //allocateMemory();
    pairs = malloc(sizeof(struct Pair) * size);
    UNT cnt = 1;
    if (pairs == NULL)
    {
        printf("MEMORY ALLOCATION FAILED! - CAN NOT ADD NEW PERSON");
        deallocHEAP();
        exit(1);
    }

    for (UNT i = 1; i < len_of_input; i++)
    {
        char current = text[i];
        if (current == text[i - 1])
        {
            cnt++;
        }
        else if (current != text[i - 1])
        {
            pairs[indx].c = text[i - 1];
            pairs[indx].n = cnt;

            //printf("(%c, %u) ",text[i-1],cnt);
            //printf("index: %u\n",indx);

            indx++;
            cnt = 1;
        }
    }
    UNT length_of_pairs = indx + 1;
    pairs[indx].c = text[len_of_input - 1];
    pairs[indx].n = cnt;
    //Encoded **result = malloc(sizeof(Encoded) * size);
    
    e_result = malloc(sizeof(struct Encoded) * size);
    if (e_result == NULL)
    {
        printf("MEMORY ALLOCATION FAILED! - CAN NOT ADD NEW PERSON");
        deallocHEAP();
        exit(2);
    }
    e_result->length = length_of_pairs;
    e_result->arr = pairs;
    return e_result;
}

char *decode(Encoded text)
{
    d_result = malloc(sizeof(char) * size);
    if (d_result == NULL)
    {
        printf("MEMORY ALLOCATION FAILED! - CAN NOT ADD NEW PERSON");
        deallocHEAP();
        exit(3);
    }
    UNT lenght = 0;
    for (UNT i = 0; i < text.length; i++)
    {
        for (UNT j = 0; j < text.arr[i].n; j++)
        {
            d_result[lenght] = text.arr[i].c;
            //printf("in result: %c in encoded: %c\n", result[lenght], text.arr[i].c);
            lenght++;
        }
    }
    d_result[lenght] = '\0';
    //printf("length: %u",lenght);
    //printf("%s",result);
    return d_result;
}