#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef HEX "123456789ABCDEF";

char    *ft_itoa_base(int nb)
{
    char    arr[21];
    int     i;
    int		j;
	ssize_t n;
	char	*out;

    n = nb;
    if (nb < 0)
        n *= -1;
    i = 20;
    if (nb == 0)
        arr[--i] = '0';
    while (n)
    {
        arr[--i] = (n % 10) + '0';
        n /= 10;
    }
	if (nb < 0)
		arr[--i] = '-';
	out = malloc((21 - i) * sizeof(char));
	if (!out)
		return (NULL);
	j = 0;
	while (arr[i])
		out[j++] = arr[i++];
	out[j] = '\0';
	return (out);
}

int main(void)
{
	printf("%s\n", ft_itoa_base(42));
	return (0);
}
