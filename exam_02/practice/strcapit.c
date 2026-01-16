#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    if (argc <= 1)
        return (printf("Erro"), 0);
    i = 1;
    while (i < argc)
        printf("%s\n", argv[i++]);
    return (0);
}

