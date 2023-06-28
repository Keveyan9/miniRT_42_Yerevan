#include "minirt.h"

<<<<<<< HEAD
int	main(int argc, char **argv)
{
	t_head	head;
	parsing(argc, argv, &head);
	
=======
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
>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba
	return (0);
}