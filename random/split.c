#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *source, char sep)
{
    char    *dup;
    int     i;
    int     j;

    if (!source)
        return (NULL);
    i = 0;
    while (source[i] && source[i] != sep)
        i++;
    dup = malloc(i + 1);
    if (!dup)
        return (NULL);
    j = 0;
    i = 0;
    while (source[i] && source[i] != sep)
    {
        dup[j] = source[i];
        j++;
        i++;
    }
    dup[j] = '\0';
    return (dup);
}

int lenword(char *source, char sep)
{
    int i;

    i = 0;
    while (source[i] && source[i] != sep)
        i++;
    return (i);
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

void    free_heap(char **source, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(source[i]);
        i++;
    }
    free(source);
}

char    **ft_split(char *source, char sep)
{
    char    **split;
    int     words;
    int     i;

    words = count_words(source, sep);
    split = (char **)malloc(words * sizeof(char *));
    if (!split)
        return (NULL);
    i = 0;
    while (i < words)
    {
        while (*source == sep)
            source++;
        split[i] = ft_strdup(source, sep);
        if (!split[i])
            return (free_heap(split, i), NULL);
        source += lenword(source, sep);
        i++;
    }
    return (split);
}

int main(void)
{
    char    source[] = "Hello World! test!";
    char    sep = ' ';
    char    *dup;
    int     count;
    int     len_word;
    char    **split;
    int     i;

    printf("%s\n", source);
    dup = ft_strdup(source, sep);
    count = count_words(source, sep);
    len_word = lenword(source, sep); 
    printf("%s\n%d\n%d\n", dup, count, len_word);
    split = ft_split(source, sep);
    i = 0;
    while (i < count)
    {
        printf("%s\n", split[i]);
        i++;
    }
    free(split);
    free(dup);
    return (0);
}

