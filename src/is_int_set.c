#include "minirt.h"

int	is_in_set(char c)
{
	int	j;

	j = -1;
	while (SPLIT_SET[++j])
	{
		if (c == SPLIT_SET[j])
			return (1);
	}
	return (0);
<<<<<<< HEAD
=======
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\f'
		|| c == '\n' || c == '\r' || c == '\v');
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
}