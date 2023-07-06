#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlxData;

	init_scene(&scene);
	parsing(argc, argv, &scene);

	mlxInit(&mlxData);
	render(&scene, &mlxData);
	free_scene(&scene);
	mlx_loop(mlxData.mlx);
	// while (1);
	return (0);
}