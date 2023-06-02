<<<<<<< HEAD
#include "../includes/minirt.h"

float ft_atof(char *str)
=======
#include "minirt.h"

float ft_atof(char *str, t_head *head)
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
{
	float result = 0.0;
	float sign = 1.0;
	float fraction = 0.1;

	while (ft_isspace(*str))
<<<<<<< HEAD
	{
		str++;
	}
=======
		str++;
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
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
<<<<<<< HEAD
	return (result);
=======
	return (result * sign);
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
}

int	ft_double_len(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		;
	return (i);
}