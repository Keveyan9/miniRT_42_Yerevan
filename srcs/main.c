#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlxData;

	init_scene(&scene);
	parsing(argc, argv, &scene);


	mlxInit(&mlxData);
	free_scene(&scene);
	render(scene, &mlxData);
	while(1);
	// mlx_loop(mlxData.mlx);
	return (0);
}