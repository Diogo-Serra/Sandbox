#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *ranged;
    int range;
    int i;

    if (start < end)
    {
        range = (end - start) + 1;
	}
    else {
		range = (start - end) + 1;
	}
    ranged = malloc(range * sizeof(int));
    if (!ranged)
        return (NULL);
    i = 0;
    while (range)
    {
        ranged[i++] = start++;
        range--;
    }
    return (ranged);
}

int main(void)
{
    int start = 1;
    int end = 3;
    int *ranged;
    int range;
    int i;

    if (start < end)
    {
        range = (end - start) + 1;
	}
    else {
		range = (start - end) + 1;
	}
    i = 0;
    ranged = ft_range(start, end);
    while (range)
    {
        range--;
        printf("%d\n", ranged[i++]);
    }
    return (0);
}
