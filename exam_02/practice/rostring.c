#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int  i;
    
    if (argc <= 1)
        return (printf("\n"), 0);
    i = 0;
    while (i < argc)
        printf("%s\n", argv[i++]);
    return (0);
}

