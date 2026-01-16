#include <stdio.h>
#include <stdlib.h>

int *ft_ranged1(int *ranged, int range, int start)
{
	int i;

	i = 0;
	while (range)
	{
		ranged[i++] = start++;
		range--;
	}
	return (ranged);
}

int *ft_ranged2(int *ranged, int range, int start)
{
	int i;

	i = 0;
	while (range)
	{
		ranged[i++] = start--;
		range--;
	}
	return (ranged);
}

int *ft_range(int start, int end)
{
	int *ranged;
	int range;

	if (start < end)
	{
		range = (end - start) + 1;
	}
	else
	{
		range = (start - end) + 1;
	}
	ranged = malloc(range * sizeof(int));
	if (!ranged)
		return (NULL);
	if (start < end)
	{
		ft_ranged1(ranged, range, start);
	}
	else
	{
		ft_ranged2(ranged, range, start);
	}
	return (ranged);
}

int main(void)
{
	int start = 3;
	int end = 1;
	int *ranged;
	int range;
	int i;

	if (start < end)
	{
		range = (end - start) + 1;
	}
	else
	{
		range = (start - end) + 1;
	}
	i = 0;
	ranged = ft_range(start, end);
	while (range)
	{
		range--;
		printf("%d\n", ranged[i++]);
	}
	free(ranged);
	return (0);
}
