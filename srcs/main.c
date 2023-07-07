#include "minirt.h"

 static int	clos(t_scene *scene)
{
	exit_code(0, "finish\n", NULL, NULL);
}

int	key_hook_man(int code, t_scene *scene)
{
	if (code == 53)
		exit_code(0, "finish_esc\n", NULL, NULL);
		printf("comand__%d\n",code);
	return (0);
}


int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlxData;

	init_scene(&scene);
	mlxInit(&mlxData);
	parsing(argc, argv, &scene);
	render(&scene, &mlxData);
	mlx_key_hook(mlxData.win, key_hook_man, &scene);
	mlx_hook(mlxData.win, 17, 0, clos, &scene);
	free_scene(&scene);
	mlx_loop(mlxData.mlx);
	return (0);
}