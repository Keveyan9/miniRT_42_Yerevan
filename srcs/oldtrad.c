// #include "minirt.h"

// void *thread_width_function(void *data)
// {
// 	t_all *all;

// 	all = data;
// 	all->check = 0;
// 	all->y = -1;
// 	while (++(all->y) < HEIGHT)
// 		calculate(all, all->x, all->y);
// 	// pthread_exit(NULL);
// }

// // static void creat_tred(t_all *all, int *count_treads, pthread_t *threads)
// // {
// // 	int result_w;
// // 	// t_all data;

// // 	result_w = 0;

// // 	// data.mlxData = all->mlxData;
// // 	// data.scene = all->scene;
// // 	// data.x = all->x;
// // 	// data.y = -1;
// // 	all->check = 0;
// // 	// thread_width_function(&data);
// // 	result_w = pthread_create(&threads[*count_treads],
// // 			NULL, thread_width_function, &all);
// // 	if (result_w != 0)
// // 	{
// // 		perror("Thread creation failed");
// // 		exit(EXIT_FAILURE);
// // 	}
// // }

// void render(t_all *all)
// {
// 	int count_treads;
// 	int cycle;
// 	int result_w;
// 	pthread_t threads[WIDTH];

// 	cycle = 0;
// 	count_treads = 0;
// 	all->x = -1;
// 	while (++(all->x) < WIDTH)
// 	{
// 		// creat_tred(all, &count_treads, threads);
// 		all->check = 1;
// 		result_w = pthread_create(&threads[count_treads++],
// 			NULL, thread_width_function, &all);
// 		if (result_w != 0)
// 		{
// 			perror("Thread creation failed");
// 			exit(EXIT_FAILURE);
// 		}
// 		// while (all->check);
// 	}
// 	while (cycle < WIDTH)
// 		pthread_join(threads[cycle++], NULL);
// 	mlx_put_image_to_window(all->mlxData->mlx, all->mlxData->win,
// 							all->mlxData->img, 0, 0);
// 	return;
// }
