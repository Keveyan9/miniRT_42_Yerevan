#include "minirt.h"

int	is_rt_file(char *path)
{
	int	len;

	len = ft_strlen(path) - 3;
	if (len > 0)
		return (ft_strncmp(path + len, ".rt", 3) == 0);
	return (0);
}

float	find_min(float a, float b, float c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b <= c)
		return (b);
	else if (c < a && c < b)
		return (c);
	else
		return (INFINITY);
}
