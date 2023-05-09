#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define SPLIT_SET " \t\v\b"

// typedef struct s_vec
// {
// 	float x;
// 	float y;
// 	float z;
// }	t_vec;

// typedef struct s_color
// {
// 	float r;
// 	float g;
// 	float b;
// }	t_color;

typedef struct s_cam
{
	//t_vec *orig;
	//t_vec *orientation;
	float origin[3];
	float orientation[3];
	float	fov;
}	t_cam;

typedef struct s_light
{
//	t_vec	*orig;
	float origin[3];
	float	ratio;
} t_light;

typedef struct s_sphere
{
//	t_vec *center;
//	t_color *tint;
	float	center[3];
	float	radius;
	int 	rgb[3];
} t_sphere;

typedef struct s_plane
{
	float point[3];
	float normal[3];
	float rgb[3];
//	t_vec *point;
//	t_vec *normal;
//	t_color *tint;
} t_plane;

typedef struct s_cylinder
{
//	t_vec *center;
//	t_vec *normal;
//	t_color *tint;
	float	radius;
	float	height;
	float	center[3];
	float	normal[3];
	int 	rgb[3];
} t_cylinder;

int 	is_in_set(char c);
char	**ft_split_m(char const *s);
void    exit_code(int code, char *msg);
int		ft_double_len(char **str);
float 	ft_atof(char *str);

#endif