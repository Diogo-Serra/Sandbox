#include <stdio.h>

void strcap(char *source)
{
    int i;
    int word;

    i = 0;
    word = 0;
    while (source[i])
    {
        while ((source[i] == ' ') || (source[i] >= 9 && source[i] <= 13))
            i++;
        if (source[i] >= 'a' && source[i] <= 'z')
        {
            if (word == 0)
            {
                word = 1;
                source[i++] += 32;
            }
            else if (word == 1)
            {
                if (source[i - 1] == ' ' || (source[i - 1] >= 9 && source[i - 1] <= 13)) 
                    word = 0;
                i++;
            }
        }
        else {
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    int     i;
    char    *cap;

    if (argc <= 1)
        return (printf("Erro"), 0);
    i = 1;
    while (i < argc)
    {
        cap = argv[i++];
        printf("%s\n", cap);
    }
    return (0);
}

