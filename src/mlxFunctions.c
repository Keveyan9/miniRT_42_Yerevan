#include "minirt.h"

// void	my_mlx_pixel_put(t_mlx *data, double x, double y, int color)
// {
// 	int		memory_offset;
// 	char	*get_data;

// 	memory_offset = y * data->line_length + x * (data->bpp / 8);
// 	get_data = data->addr + memory_offset;
// 	*(unsigned int *)get_data = color;
// }

// void    mlxInit(t_mlx *mlxData, float width, float height)
// {
//     mlxData->mlx = mlx_init();
//     mlxData->win = mlx_new_window(mlxData->mlx, width, height, "miniRT");
//     mlxData->img = mlx_new_image(mlxData->mlx, width, height);
//     mlxData->addr = mlx_get_data_addr(mlxData->img, &mlxData->bpp, &mlxData->line_length, &mlxData->endian);
// }
