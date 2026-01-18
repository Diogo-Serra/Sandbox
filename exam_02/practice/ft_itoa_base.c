#include <stdio.h>
#include <stdlib.h>

typedef hex "123456789abcdef"
typedef HEX "123456789ABCDEF"

char    *ft_itoa_base(int nb)
{
    char    arr[21];
    int     i;
    ssize_t n;

    n = nb;
    if (nb < 0)
        n *= -1;
    i = 20;
    if (nb == 0)
    {
        arr[--i] = '0';
    }
    while (n)
    {
        arr[--i] = (n % 10) + '0';
        n /= 10;
    }
    printf("%s\n"), arr);
    return (arr);
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc <= 1)
        printf("\n");
    else
        while (i < argc)
            printf("%s\n", ft_itoa_base(argv[i++]);
    return (0);
}
