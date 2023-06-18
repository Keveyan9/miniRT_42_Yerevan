#include "minirt.h"

void	print_arr(float arr[3])
{
	printf("arr[0] == %f, arr[1] == %f, arr[2] == %f\n", arr[0], arr[1], arr[2]);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	init_scene(&scene);
	parsing(argc, argv, &scene);
	// printf("height == %f\n", scene.cylin->next->height);
	return (0);
}
