#include "minirt.h"

int	main(int argc, char **argv)
{
	t_head	head;

	init_head(&head);
	parsing(argc, argv, &head);
	printf("head->ratio == %f\n", head.amb->ratio);
	return (0);
}