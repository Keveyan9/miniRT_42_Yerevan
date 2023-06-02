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
	t_head	head;

	init_head(&head);
	parsing(argc, argv, &head);
	print_arr(head.amb->tint);
	// print_arr(head.cylin->normal);
	// print_arr(head.cylin->tint);
	// printf("height == %f\n", head.cylin->height);
	// printf("radius == %f\n", head.cylin->radius);
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
	return (0);
}