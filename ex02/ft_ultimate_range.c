#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int *array;
	int i;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (-1);
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (size);
}
