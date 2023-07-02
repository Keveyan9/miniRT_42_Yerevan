#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	//t_mlx	mlxData;
	(void)argc;
	(void)argv;

	init_scene(&scene);
	parsing(argc, argv, &scene);
	while(1);

	//mlxInit(&mlxData);
	// render(scene, &mlxData);
	// mlx_loop(mlxData.mlx);
	return (0);
}