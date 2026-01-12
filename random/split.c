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

int main(void)
{
    char    source[] = "Hello World!";
    char    sep = ' ';
    char    *dup;

    printf("Hello World\n");
    dup = ft_strdup(source, sep);
    printf("%s\n", dup);
    return (0);
}

