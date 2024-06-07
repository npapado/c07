#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	char	*current;
	int		total_length;
	int		sep_length;
	int		i;
	int		j;
	int		k;
	
	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result != NULL)
		{
			*result = '\0';
		}
		return (result);
	}
	total_length = 0;
	sep_length = 0;
	i = 0;
	while (sep[sep_length] != '\0')
	{
		sep_length++;
	}
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total_length++;
			j++;
		}
		i++;
	}
	total_length += sep_length * (size - 1);
	result = (char *)malloc(total_length + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	current = result;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			*current = strs[i][j];
			current++;
			j++;
		}
		if (i < size - 1)
		{
			k = 0;
			while (k < sep_length)
			{
				*current = sep[k];
				current++;
				k++;
			}
		}
		i++;
	}
	*current = '\0';
	return (result);
}
