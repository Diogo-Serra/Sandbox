#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *rrange;
    int range;
    int i;

    i = 0;
    if (start < end && start > 0)
    {
        range = (end - start) + 1;
        rrange = malloc(range * sizeof(ssize_t));
        if (!rrange)
        	return (NULL);
        while (start <= end)
        	rrange[i++] = end--;
    }
    if (end < start && start > 0)
    {
        range = (start - end) + 1;
	rrange = malloc(range * sizeof(ssize_t));
	if (!rrange)
		return (NULL);
	while (end <= start)
		rrange[i++] = end++;
    }
    return (rrange);
}

int main(void)
{
    int *rrange;
    int start = 3;
    int end = 1;
    int i;

    rrange = ft_rrange(start, end);
    i = 0;
    while (end <= start)
    {
        printf("%d", rrange[i++]);
        end++;
    }
    free(rrange);
    return (0);
}
