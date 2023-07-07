#include "minirt.h"

int	clos(t_scene *scene)
{
	exit_code(0, "finish\n", scene, NULL);
	return(0);

}


// int camera_direction(int code, t_oll *oll)
// {
// 	int k;

// 	k = 0.5;
// 	if (code == 65362 || code == 126)
// 		oll->scene->cam->orientation.y = oll->scene->cam->orientation.y + k;
// 	else if (code == 65364 || code == 125)
// 		oll->scene->cam->orientation.y = oll->scene->cam->orientation.y - k;
// 	else if (code == 65361 || code == 123)
// 		oll->scene->cam->orientation.x = oll->scene->cam->orientation.x + k;
// 	else if (code == 65363 || code == 124)
// 		oll->scene->cam->orientation.x = oll->scene->cam->orientation.x - k;
// 	else if (code == 65436 )
// 		oll->scene->cam->orientation.z = oll->scene->cam->orientation.z + k;
// 	else if (code == 65438)
// 		oll->scene->cam->orientation.z = oll->scene->cam->orientation.z - k;
// 	render(oll->scene, oll->mlxdata);
// 	return(0);
// }



int camera_direction(int code, t_oll *oll)
{
	int k;

	k = 5;
	if (code == 65362 || code == 126)
		oll->scene->light->orig.y = oll->scene->light->orig.y + k;
	else if (code == 65364 || code == 125)
		oll->scene->light->orig.y = oll->scene->light->orig.y - k;
	else if (code == 65361 || code == 123)
		oll->scene->light->orig.x = oll->scene->light->orig.x + k;
	else if (code == 65363 || code == 124)
		oll->scene->light->orig.x = oll->scene->light->orig.x - k;
	else if (code == 65436 )
		oll->scene->light->orig.z = oll->scene->light->orig.z + k;
	else if (code == 65438)
		oll->scene->light->orig.z = oll->scene->light->orig.z - k;
	render(oll->scene, oll->mlxdata);
	return(0);
}



int	key_hook_man(int code, t_oll *oll)
{
	int k;

	k = 5;
	// printf("code_%d\n",code);
	if (code == 65307 || code == 53)
		exit_code(0, "finish_esc\n", NULL, NULL);
	else if (code == 119 || code == 13)
		oll->scene->cam->orig.y = oll->scene->cam->orig.y + k;
	else if (code == 115 || code == 1)
		oll->scene->cam->orig.y = oll->scene->cam->orig.y - k;
	else if (code == 97 || code == 0)
		oll->scene->cam->orig.x = oll->scene->cam->orig.x + k;
	else if (code == 100 || code == 2)
		oll->scene->cam->orig.x = oll->scene->cam->orig.x - k;
	else if (code == 113 )
		oll->scene->cam->orig.z = oll->scene->cam->orig.z + k;
	else if (code == 101)
		oll->scene->cam->orig.z = oll->scene->cam->orig.z - k;
	camera_direction(code,oll);
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
	mlx_loop(mlxData.mlx);
	free_scene(&scene);
	return (0);
}