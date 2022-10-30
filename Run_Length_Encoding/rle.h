//SOBHAN BAHRAMI
#ifndef RLE_H
#define RLE_H

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

int validateEntry(char *str);
void deallocHEAP();
Encoded *encode(char *text);
char *decode(Encoded text);

#endif