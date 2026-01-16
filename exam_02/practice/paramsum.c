#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *source)
{
    int     i;
    int     sign;
    int     digit;

    i = 0;
    sign = 1;
    while (source[i] == ' ' || (source[i] > 9 && source[i] < 13))
        i++;
    if (source[i] == '+' || source[i] == '-')
    {
        if (source[i] == '-')
            sign *= -1;
        i++;
    }
    digit = 0;
    while (source[i] > '0' && source[i] < '9')
        digit = digit * 10 + (source[i++] - '0');
    return (digit * sign);
}

int main(int argc, char **argv)
{
    int count;
    int i;

    if (argc <= 1)
        return (printf("No Parameters"), 0);
    count = 0;
    i = 1;
    while (i < argc)
        count += ft_atoi(argv[i++]);
    printf("%d\n", count);
    return (0);
}
