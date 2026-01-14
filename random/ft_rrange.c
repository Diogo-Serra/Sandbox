#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *rrange;
    int range;
    int i;

    i = 0;
    rrange = NULL;
    if (start < end)
    {
        range = (end - start) + 1;
        rrange = malloc(range * sizeof(ssize_t));
        if (!rrange)
        	return (NULL);
        while (start <= end)
        	rrange[i++] = end--;
	return (rrange);
    }
    else if (end < start)
    {
        range = (start - end) + 1;
	rrange = malloc(range * sizeof(ssize_t));
	if (!rrange)
		return (NULL);
	while (end <= start)
		rrange[i++] = end++;
	return (rrange);
    }
    return (rrange);
}

int main(void)
{
    int *rrange;
    int start = 1;
    int end = 3;
    int i;

    rrange = ft_rrange(start, end);
    i = 0;
    while (start <= end)
    {
        printf("%d", rrange[i++]);
        end--;
    }
    free(rrange);
    return (0);
}
