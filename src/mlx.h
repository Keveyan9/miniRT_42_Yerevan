#ifndef MLX_H
# define MLX_H

#include "minirt.h"

typedef struct s_mlx
{
    void    *win;
    void    *mlx;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
}   t_mlx;

#endif