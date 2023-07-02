#include	"minirt.h"

void	exit_code(int code, char *msg, t_scene *scene)
{
	write(2, msg, ft_strlen(msg));
	free_scene(scene);
	exit(code);
}