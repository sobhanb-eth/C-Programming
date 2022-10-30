#include <stdio.h>


int Collatz (long int a) {
    long int calc;
    if (a == 1) {
        calc = a;
    }else if (a%2==0){
        calc = a/2;
    }else if (a%2!=0) {
        calc = (a*3+1);
    }
    return calc;
}

int main () {

    long int init; scanf("%li", &init);
    int sentinle = 1;
    int cnt = 0;
    long int current = init;
    printf("%li, ", init);
    while (current != sentinle) {
        current = Collatz(current);
        printf("%li", current);
        if (current!=1){
            printf(", ");
        }
        cnt++;  
    }
    printf("\n");
    printf("%d\n", cnt+1);
    return 0;
}