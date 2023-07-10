#ifndef MYMMlX_H
# define MYMMlX_H

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

typedef struct s_all
{
	t_mlx	*mlx_data;
	t_scene	*scene;
}	t_all;

#endif