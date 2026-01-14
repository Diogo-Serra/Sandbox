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
        while (start < end)
            rrange[i++] = end--;
    }
    return (rrange);
}

int main(void)
{
    int *rrange;
    int range;
    int start = 1;
    int end = 3;
    int i;

    rrange = ft_rrange(start, end);
    range = (end - start) + 1;
    i = 0;
    while (start < end)
    {
        printf("%d", rrange[i++]);
        start++;
    }
    free(rrange);
    return (0);
}
