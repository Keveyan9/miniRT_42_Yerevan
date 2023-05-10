#include "minirt.h"

void	print_arr(float arr[3])
{
	printf("arr[0] == %f, arr[1] == %f, arr[2] == %f\n", arr[0], arr[1], arr[2]);
}

int	main(int argc, char **argv)
{
	t_head	head;

	init_head(&head);
	parsing(argc, argv, &head);
	print_arr(head.cam->orig);
	print_arr(head.cam->orientation);
	printf("fov == %f\n", head.cam->fov);
	return (0);
}