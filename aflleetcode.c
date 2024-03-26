// gcc -o p aflleetcode.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s = malloc(20 * sizeof(char));
    char *p = malloc(20 * sizeof(char));
    int i, j;
    char traversalch;
    char tempch, tempch2;
    int numberofoccurences = 0;
    char chp1, chp2;
    int pindex = 0;
    int valid = 1;

    printf("Enter string for s: ");
    scanf("%s", s);

    printf("Enter string for p: ");
    scanf("%s", p);

    for (i = 0; s[i + 1] != '\0'; i++)
    {
        tempch = s[i];
        tempch2 = s[i + 1];
        if (tempch == '.' && tempch2 == '*')
            return 1;
    }

    for (i = 0; s[i] != '\0';)
    {
        traversalch = s[i];
        tempch = s[i];
        for (j = i; tempch == traversalch; j++)
        {
            tempch = s[j];
            numberofoccurences++;
        }
        chp1 = p[pindex];
        chp2 = p[pindex + 1];
        if (chp2 == '*')
        {
            if (chp1 != s[i])
                valid = 0;
            pindex = pindex + 2;
        }
        else
        {
            if (chp1 != s[i] || numberofoccurences > 1)
                valid = 0;
            pindex = pindex + 1;
        }
        i = j + 1;
        numberofoccurences = 0;
    }
    return valid;
}