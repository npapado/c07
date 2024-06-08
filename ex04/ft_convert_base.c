#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base);

int		is_valid_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ' || base[i] > '~')
		{
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i > 1);
}

int		base_value(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		result;
	int		sign;
	int		base_len;
	int		val;

	result = 0;
	sign = 1;
	base_len = 0;
	while (base[base_len])
	{
		base_len++;
	}
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while ((val = base_value(*str, base)) >= 0)
	{
		result = result * base_len + val;
		str++;
	}
	return (result * sign);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		base_len;
	int		num_len;
	int		n;
	char	*result;
	int		is_negative;

	base_len = 0;
	num_len = (nbr <= 0) ? 1 : 0;
	is_negative = (nbr < 0);
	while (base[base_len])
	{
		base_len++;
	}
	n = nbr;
	while (n)
	{
		num_len++;
		n /= base_len;
	}
	result = (char *)malloc(num_len + 1);
	if (!result)
	{
		return (NULL);
	}
	result[num_len] = '\0';
	if (is_negative)
	{
		result[0] = '-';
	}
	while (num_len > 0 && nbr)
	{
		result[--num_len] = base[(is_negative ? -(nbr % base_len) : (nbr % base_len))];
		nbr /= base_len;
	}
	if (num_len == 1 && is_negative)
	{
		result[0] = '-';
	}
	else if (num_len == 1)
	{
		result[0] = base[0];
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;

	num = 0;
	result = NULL;

	if (!nbr || !base_from || !base_to || !is_valid_base(base_from) || !is_valid_base(base_to))
	{
		return (NULL);
	}
	num = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(num, base_to);

	return (result);
}
