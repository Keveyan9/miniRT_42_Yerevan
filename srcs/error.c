#include	"/Users/zkarapet/Desktop/newminirt/includes/minirt.h"

void	exit_code(int code, char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(code);
}