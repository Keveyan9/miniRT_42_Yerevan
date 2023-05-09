#include "minirt.h"

float ft_atof(char *str)
{
	float result = 0.0;
	float sign = 1.0;
	float fraction = 0.1;

	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			result += (*str - '0') * fraction;
			fraction /= 10.0;
			str++;
		}
	}
	return (result);
}

int	ft_double_len(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		;
	return (i);
}