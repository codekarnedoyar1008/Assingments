#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define max_alpha 90
#define min_alpha 65
#define max_numeric 57
#define min_numeric 48
char *string(char *p_string, int size){
    for (int i = 0; i < size; i++)
    {
        int toss = rand() % 2;

        if (toss == 0)
        {
            p_string[i] = rand() % 26 + 'A';
        }
        else
        {
            p_string[i] = rand() % 10 + '0';
        }
    }

    p_string[size] = '\0';
    return p_string;
}
char *alias(char *p_string_alias, char *p_string, int size, int ini){
    if (ini == size)
    {
        return p_string_alias;
    }
    p_string_alias[ini] = p_string[ini];
    alias(p_string_alias, p_string, size, ini + 1);
    return p_string_alias;
}
int main()
{   int nor=0;
    srand(time(0));
    int size = rand()%10+10;
    int ini = 0;
    char *p_string = (char *)calloc(size + 1, sizeof(char));
    p_string = string(p_string, size);
    printf("\nString is : %s --> %d\n", p_string, size);
    printf("\n");
    char *p_string_alias = NULL;
    p_string_alias = (char *)calloc(size + 1, sizeof(char));
    p_string_alias[size + 1] = '\0';
    p_string_alias = alias(p_string_alias, p_string, size, ini);
    printf("\nAlias string is : %s --> %d\n", p_string_alias, size);
    printf("\n");
    char *norepeat = NULL;
    norepeat = (char *)calloc(size, sizeof(char));
    int norepeat_index = 0;
    for (int i = 0; i < size; i++)
    {
        bool is_repeated = false;

        for (int j = 0; j < size; j++)
        {
            if (i != j && p_string[i] == p_string[j])
            {
                is_repeated = true;
                break;
            }
        }

        if (!is_repeated)
        {
            norepeat[norepeat_index++] = p_string[i];
            nor++;
        }
    }
    norepeat[norepeat_index] = '\0';
    printf("\nNon-repeating string is : %s --> %d\n", norepeat,nor);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (nor!=1)
        {
            printf("String cannot be a palindrome..\n\n");
            break;
        }
        else
        {
            int poss=1;
            for (int i = 1; i < size; i++)
            {
                poss = poss * 2;
            }
            printf("String can be palindrome with total of %d possiblities..\n\n", poss);
            break;
        }
    }
    free(p_string);
    free(p_string_alias);
    free(norepeat);
    return 0;
}