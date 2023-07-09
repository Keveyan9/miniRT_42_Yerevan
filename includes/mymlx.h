#ifndef	MYMLX_H
# define MYMLX_H

# include "minirt.h"

typedef struct s_mlx
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_oll
{
    t_mlx    *mlxdata;
    t_scene *scene;
}   t_oll;

#endif