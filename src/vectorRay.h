#ifndef VECTORRAY_H
# define VECTORRAY_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ray
{
	float	t;
	t_vec	orig;
	t_vec	dir;
}	t_ray;

#endif