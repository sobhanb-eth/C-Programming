//SOBHAN BAHRAMI - EDNQOR - ASSIGNMENT 5
#include <stdio.h>
#include "rle.h"

int main()
{

    char text[255];
    scanf("%s", text);
    if (validateEntry(text))
    {

        Encoded *enc = encode(text);
        for (UNT i = 0; i < enc->length; i++)
        {
            printf("(%c, ", enc->arr[i].c);
            printf("%u) ", enc->arr[i].n);
        }
        printf("-> %s\n", decode(*enc));
    }
    else
    {
        printf("BAD INPUT!\n");
        return 0;
    }
    deallocHEAP();
    return 0;
}