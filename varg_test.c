#include "libft.h"

int total(int n, ...);
int max(int n, ...);
double avg_int(int count, ...);
int count_equal(int count, int target, ...);
char *join_strings(int count, ...);

int main(void)
{
    char *joined;

    printf("total = %d\n", total(5, 2, 32, 43, 5, 20));
    printf("max = %d\n", max(5, 2, 32, 43, 5, 20));
    printf("average = %f\n", avg_int(3, 10, 15, 20));
    printf("targets = %d\n", count_equal(5, 1, 3, 4, 1, 2, 1));
    joined = join_strings(3, "one", "two", "three");
    printf("joined = %s\n", joined);
	free (joined);
}

char *join_strings(int count, ...)
{
    va_list pargs;
    char    *joined;
    int     i;

	i = -1;
	va_start(pargs, count);
	while (++i < count)
	{
		if (i == 0)
			joined = ft_strdup(va_arg(pargs, char *));
		else
			joined = ft_strjoin_free(joined, va_arg(pargs, char *));
	}
	va_end(pargs);
    return (joined);
}
int count_equal(int count, int target, ...)
{
    va_list pargs;
    int     targets;
    int     i;

    i = 0;
    targets = 0;
    va_start(pargs, target);
    while (i < count)
    {
        if (target == va_arg(pargs, int))
            targets++;
        i++;
    }
    return (targets);
}
double avg_int(int count, ...)
{
    va_list pargs;
    int     total;
    int     i;

    i = 0;
    total = 0;
    va_start(pargs, count);
    while (i < count)
    {
        total += va_arg(pargs, int);
        i++;
    }
    return (float)(total / count);
}

int total(int n, ...)
{
    va_list pa;
    int     total;
    int     i;

    i = 0;
    total = 0;
    va_start(pa, n);
    while (i < n)
    {
        total += va_arg(pa, int);
        i++;
    }
    return (total);
}

int max(int n, ...)
{
    va_list pa;
    int     max;
    int     x;
    int     i;

    i = 0;
    x = 0;
    max = 0;
    va_start(pa, n);
    while (i < n)
    {
        x = va_arg(pa, int);
        if (i == 0)
            max = x;
        else if (x > max)
            max = x;
        i++;
    }
    return (max);
}

