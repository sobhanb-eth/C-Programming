#include<stdio.h>

int main()
{

    int numOfRow = 1;
    scanf("%d", &numOfRow);

    if (numOfRow > 1)
    {
        for (int i = 1; i <= numOfRow; i++)
        {
            for (int ka=numOfRow; ka > i; ka--){
                    printf(" ");
                }

            for (int k = 1; k <= i; k++){
                printf("X");
            }

            printf("  ");

            for (int j = 1; j <= i; j++)
            {
                printf("X");
            }
            printf("\n");
        }
    }
    else
    {
        //do nothing
    }
    return 0;
}