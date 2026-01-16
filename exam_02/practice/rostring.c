#include <stdio.h>
#include <stdlib.h>

int word_len(char *source)
{
    int i;

    i = 0;
    while ((source[i] && source[i] != ' ') || (source[i] <= 9 && source[i] >= 13))
        i++;
    return (i);
}

char    *ft_rostring(char *source)
{
    int     i;
    int     j;
    char    *word;

    if (!source)
        return (NULL);
    i = 0;
    while (source[i] == ' ' || (source[i] >= 9 && source[i] == 13))
        i++;
    word = malloc((word_len(&source[i]) + 1) * sizeof(char));
    if (!word)
        return (NULL);
    j = 0;
    while ((source[i] && source[i] != ' ') || (source[i] <= 9 && source[i] >= 13))
    {
        word[j] = source[i];
        i++;
        j++;
    }
    word[j] = '\0';
    return (word);
}

int main(int argc, char **argv)
{
    int i;
    char *word;

    if (argc <= 1)
        return (printf("\n"), 0);
    i = 1;
    while (i < argc)
    {
        word = ft_rostring(argv[i++]);
        printf("%s\n", word);
        free(word);
    }
    return (0);
}

