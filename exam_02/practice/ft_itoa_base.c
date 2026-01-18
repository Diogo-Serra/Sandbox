#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define HEX "0123456789ABCDEF"
# define hex "0123456789abcdef"
# define dec "0123456789"
# define bin "01"

char    *ft_itoa_base(int nb, char *base)
{
    char    arr[32];
	int		ibase;
    int     i;
    int		j;
	long	n;
	char	*out;

	i = 0;
	while (base[i])
		i++;
	ibase = i;
	if (ibase < 2)
		return (NULL);
    n = nb;
    if (n < 0)
        n = -n;
    i = 31;
    if (nb == 0)
        arr[--i] = '0';
    while (n)
    {
        arr[--i] = base[n % ibase];
        n /= ibase;
    }
	if (nb < 0 && ibase == 10)
		arr[--i] = '-';
	out = malloc((32 - i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	j = 0;
	while (i < 32)
		out[j++] = arr[i++];
	out[j] = '\0';
	return (out);
}

int main(void)
{
	printf("42 in hex: %s\n", ft_itoa_base(42, hex));
	printf("-42 in dec: %s\n", ft_itoa_base(-42, dec));
	printf("255 in HEX: %s\n", ft_itoa_base(255, HEX));
	printf("15 in bin: %s\n", ft_itoa_base(15, bin));
	return (0);
}
