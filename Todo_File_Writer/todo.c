#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef int Bool;

/*
Create a program which reads times and notes as command line arguments and writes these time-note pairs to a file. Input format: <time> <note> <time> <note>...
The output file name should be todolist.txt. If all arguments are correct then don't print anything to the output. If too few arguments are given (0 or 1 input) then print "Wrong input!" and finish execution.

 

In case of wrong input, the program should print "Wrong input!" (as many times as many wrong inputs there are) and continue the processing of further time-note pairs. The input is wrong if:
- arguments are not meeting the requirements of the format
- any time is not a proper time between 00:00 and 23:59
- any note contains characters other than the lower or upper case English alphabet (you don't need to deal with accented letters)

 

Correctness of time should be checked in function "isValidTime()" and correctness of notes should be checked in "isValidNote()".

 

Correct example:
./todo 13:58 assignment 00:00 sleep 08:30 breakfast

 

Incorrect examples:
./todo 13:58 assignment 24:00 sleep 08:30 breakfast
./todo 13:58 assignment sleep 00:00 08:30 breakfast

 

In the first example, the time component of the second pair is incorrect. After testing "24:00" the processing should continue with testing 08:30. In the second example, the components of the second pair are swapped. After testing "sleep" we continue with processing 08:30. You may assume that the input is not missing a time or a note. In the worst case, only their format is wrong.

 

Example todolist.txt:
13:58 - assignment
00:00 - sleep
08:30 - breakfast
*/

Bool isValidTime(char* ch)
{
    if (strlen(ch)>6){
        return false;
    }
    char str[6];
    char hrs[3];
    char minute[3];
    for (int i = 0; i<6; i++) {
        str[i] = ch[i];
    }
    /*char to string*/
    hrs[0] = str[0];
    hrs[1] = str[1];
    hrs[2] = '\0';
    minute[0] = str[3];
    minute[1] = str[4];
    minute[2] = '\0';

    if (str[2] == ':') {
        if ((atoi(hrs) > 23) || (atoi(minute)>59)) {
            return false;
        }
        return true;
    } else {
        return false;
    }
}

Bool isValidNote(char* ch)
{
    int len = strlen(ch);
    int pass = 1;
    //utilizing ascii int values, checks if all characters of the string are either upper or lower case letters.
    for (int i=0; i<len; i++) {
        if (((int)(ch[i]) < 97 || (int)(ch[i]) > 122) && ((int)(ch[i]) < 65 || (int)(ch[i]) > 90)) {
            pass = 0;
            return false;
        }
    }

    if (pass == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char *argv[])
{
    //If too few arguments are given (0 or 1 input) then print "Wrong input!" and finish execution.
    if (argc < 2)
    {
        printf("Wrong input!\n");
        return 1;
    }
    else
    {
        FILE *fptr;
        
        int len = argc;

        for (int i = 1; i < len; i++)
        {
            if ((isValidTime(argv[i])) && (isValidNote(argv[i+1])))
                {
                    //printf("argv - time: %s & argv - note: %s  && VALID!\n", argv[i],argv[i+1]);
                    fptr = fopen("todolist.txt", "a");
                    fprintf(fptr,"%s - %s\n",argv[i],argv[i+1]);
                    fclose(fptr);
                }
                else
                {
                    printf("Wrong Input!\n");
                }
                //Program starts the index from 1 because index 0 is the file name, since it checks the current and next index, the index should be incremented
                //so that it checks from the next unchecked index.
                ++i;
        }
        return 0;
    }
}