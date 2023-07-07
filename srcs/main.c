#include "minirt.h"

 static int	clos(t_scene *scene)
{
	exit_code(0, "finish\n", NULL, NULL);
}

int	key_hook_man(int code, t_oll *oll)
{
	if (code == 65307 || code == 53)
		exit_code(0, "finish_esc\n", NULL, NULL);
	else if (code == 119 || code == 13)
	{
		//printf("scene ferst__%f\n",oll->scene->cam->orientation.y);
		oll->scene->cam->orig.y = oll->scene->cam->orig.y + 0.1;
		//printf("scene__%f\n",oll->scene->cam->orientation.y);
	}
	else if (code == 115 || code == 1)
	{
		oll->scene->cam->orig.y--;
		printf("scene__%f\n",oll->scene->cam->orientation.y);
	}
	render(oll->scene, oll->mlxdata);
	return (0);
}


int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlxData;
	t_oll 	oll;

	oll.scene = &scene;
	oll.mlxdata = &mlxData;

	init_scene(&scene);
	mlxInit(&mlxData);
	parsing(argc, argv, &scene);
	mlx_key_hook(mlxData.win, key_hook_man, &oll);
	mlx_hook(mlxData.win, 17, 0, clos, &scene);
	render(&scene, &mlxData);
	free_scene(&scene);
	mlx_loop(mlxData.mlx);
	return (0);
}