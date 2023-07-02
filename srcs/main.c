#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlxData;

	init_scene(&scene);
	mlxInit(&mlxData);
	parsing(argc, argv, &scene);

	render(scene, &mlxData);
	mlx_loop(mlxData.mlx);
	return (0);
}