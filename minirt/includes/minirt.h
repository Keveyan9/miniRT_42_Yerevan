#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# define SPLIT_SET " \t\v\b"

enum e_objs
{
	A,
	C,
	L,
	pl,
	sp,
	cy
};

typedef struct s_vec
{
	float x;
	float y;
	float z;
}	t_vec;

typedef struct s_color
{
	float r;
	float g;
	float b;
}	t_color;

typedef struct s_cam
{
	t_vec *orig;
	t_vec *orientation;
	float	fov;
}	t_cam;

typedef struct s_light
{
	t_vec	*orig;
	float	ratio;
} t_light;

typedef struct s_sphere
{
	t_vec *center;
	t_color *tint;
	float radius;
} t_sphere;

typedef struct s_plane
{
	t_vec *point;
	t_vec *normal;
	t_color *tint;
} t_plane;

typedef struct s_cylinder
{
	t_vec *center;
	t_vec *normal;
	float radius;
	float height;
	t_color *tint;
} t_cylinder;

int is_in_set(char c);
char	**ft_split_m(char const *s);
void    exit_code(int code, char *msg);

#endif