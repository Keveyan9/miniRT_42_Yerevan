#include "minirt.h"

void	*thread_width_function(void *data)
{
	t_all		*all;
	int			xy[2];

	all = data;
	xy[0] =	all->x;
	all->check = 0;
	xy[1] = -1;
	while (++(xy[1]) < HEIGHT)
		calculate(all, xy[0], xy[1]);
	pthread_exit (NULL);
}

void	render(t_all *all)
{
	int			result_w;
	int			count_treads;
	int			cycle;
	pthread_t	threads[WIDTH];

	result_w = 0;
	cycle = 0;
	count_treads = 0;
	all->x = -1;
	while (++(all->x) < WIDTH)
	{
		all->check = 1;
		result_w = pthread_create(&threads[count_treads++],
				NULL, thread_width_function, all);
		if (result_w != 0)
		{
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
		while (all->check);
	}
	while (cycle < WIDTH)
		pthread_join(threads[cycle++], NULL);
	mlx_put_image_to_window(all->mlxData->mlx, all->mlxData->win,
		all->mlxData->img, 0, 0);
	return ;
}
