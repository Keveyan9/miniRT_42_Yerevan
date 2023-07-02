#include "minirt.h"

int vector_range_check(t_vec *vector, float lower_bound, float upper_bound)
{
	if ((vector->x < lower_bound || vector->x > upper_bound)
		|| (vector->y < lower_bound || vector->y > upper_bound)
		|| (vector->z < lower_bound || vector->z > upper_bound))
		return (0);
	return (1);
}

int vector_norm_check(t_vec *vector)
{
	float	len;

	len = vecNorm(*vector);
	if (len > 1 || len < 0)
		return (0);
	return (1);
}

int color_range_check(t_color *tint)
{
	if ((tint->r < 0 || tint->r > 255)
		|| (tint->g < 0 || tint->g > 255)
		|| (tint->b < 0 || tint->b > 255))
		return (0);
	return (1);
}

int	only_digit_in_str(char *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (s[0] == '\n')
		return (0);
	if (s[0] == '-' || s[0] == '+')
	{
		k = 1;
		i++;
	}
	while (s && s[i] != '\n' && s[i] && i < ft_strlen(s))
	{
		if (!ft_isdigit(s[i]) && k == 0 && s[i] != '.')
			return (0);
		else if (s[i] == '.' && s[i + 1] && !ft_isdigit(s[i + 1]))
			return (0);
		i++;
	}
	return (1);
}