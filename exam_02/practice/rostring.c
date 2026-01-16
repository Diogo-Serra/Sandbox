#include <stdio.h>
#include <stdlib.h>

void    ft_rostring(char *source)
{
    int i;
    int w;
    int r;
    char *word;
    char *rot;

    i = 0;
    while (source[i] == ' ' || (source[i] >= 9 && source[i] <= 13))
        i++;
}

int main(int argc, char **argv)
{
    int i;

    if (argc <= 1)
        return (printf("\n"), 0);
    i = 0;
    while (i < argc)
    {
        printf("%s\n", argv[i++]);
    }
    return (0);
}

