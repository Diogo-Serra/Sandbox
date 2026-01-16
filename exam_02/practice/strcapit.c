#include <stdio.h>

void strcap(char *source)
{
    int i;

    i = 0;
    while (source[i])
    {
        if (i == 0 || source[i - 1] == ' ' || (source[i - 1] >= 9 && source[i - 1] <= 13))
        {
            if (source[i] >= 'a' && source[i] <= 'z')
                source[i] -= 32;
        }
		else if (source[i] >= 'A' && source[i] <= 'Z')
			source[i] += 32;
        i++;
    }
}

int main(int argc, char **argv)
{
    int     i;

    if (argc <= 1)
        return (printf("Erro"), 0);
    i = 1;
    while (i < argc)
    {
        strcap(argv[i]);
        printf("%s\n", argv[i]);
        i++;
    }
    return (0);
}

