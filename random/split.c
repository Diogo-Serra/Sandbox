#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *source, char sep)
{
    char    *dup;
    int     i;
    int     j;

    if (!source || !sep)
        return (NULL);
    i = 0;
    while (source[i] && source[i] != sep)
        i++;
    dup = malloc(i + 1);
    if (!dup)
        return (NULL);
    dup[i] = '\0';
    j = 0;
    while (j < i)
    {
        dup[j] = source[j];
        j++;
    }
    return (dup);
}

int count_words(char *source, char sep)
{
    int i;
    int count;

    if (!source || !sep)
        return (0);
    i = 0;
    count = 0;
    while (source[i])
    {
        if (source[i] != sep && (i == 0 || source[i - 1] == sep))
            count++;
        i++;
    }
    return (count);
}

int main(void)
{
    char    source[] = "Hello World! test!";
    char    sep = ' ';
    char    *dup;
    int     count;

    printf("%s\n", source);
    dup = ft_strdup(source, sep);
    count = count_words(source, sep);
    printf("%s\n%d\n", dup, count);
    free(dup);
    return (0);
}

