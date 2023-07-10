/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:19:19 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 21:19:25 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	*thread_width_function(void *data)
{
	t_all		*all;
	int			xy[2];

	all = data;
	xy[0] = all->x;
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
			exit_code("Thread creation failed", EXIT_FAILURE);
		while (all->check)
			;
	}
	while (cycle < WIDTH)
		pthread_join(threads[cycle++], NULL);
	mlx_put_image_to_window(all->mlx_data->mlx, all->mlx_data->win,
		all->mlx_data->img, 0, 0);
	return ;
}
