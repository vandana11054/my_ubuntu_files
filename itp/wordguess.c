

#include <stdio.h>

int main()
{
    char word[] = "believer";
    int count = 6;
    char pi;
    printf("word guessing game\n");
    printf("attempts 6\n");
    char cs[8];
    char cs1[8];
    for (int i = 0; i < 8; i++)
    {
        cs[i] = '_';
        cs1[i] = '_';
    }

    while (count != 0)
    {
        printf("guess: ");
        scanf(" %c", &pi);

        int found = 0;

        for (int i = 0; i < 8; i++)
        {
            if (pi == word[i])
            {
                cs[i] = pi;
                found = 1;
            }
        }

        if (!found)
        {
            count--;
        }

        for (int i = 0; i < 8; i++)
        {
            if (cs[i] != '_')
            {
                cs1[i] = cs[i];
            }
        }

        printf("Your guess is %c \n", pi);

        for (int i = 0; i < 8; i++)
        {
            if (cs1[i] != '_' && word[i] != cs1[i])
            {
                printf("_");
            }
            else
            {
                printf("%c", cs1[i]);
            }
        }
        printf("\n");

        printf("attempts left %d \n", count);

        int word_guessed = 1;
        for (int i = 0; i < 8; i++)
        {
            if (word[i] != cs1[i])
            {
                word_guessed = 0;
                break;
            }
        }

        if (word_guessed)
        {
            printf("Hurray! You won\n");
            break;
        }
    }

    if (count == 0)
    {
        printf("Sorry, try again\n");
    }

    return 0;
}
