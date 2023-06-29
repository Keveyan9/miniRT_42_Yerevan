#include "minirt.h"

// void	print_arr(float arr[3])
// {
// 	printf("arr[0] == %f, arr[1] == %f, arr[2] == %f\n", arr[0], arr[1], arr[2]);
// }

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlxData;

	init_scene(&scene);
	mlxInit(&mlxData);
	parsing(argc, argv, &scene);
	//render(scene, &mlxData);
	return (0);
}