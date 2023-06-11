#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# include <float.h>
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# define SPLIT_SET	" \t\v\b"

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

typedef struct s_ambient
{
	float	ratio;
	t_color	tint;
}	t_ambient;

typedef struct s_cam
{
	t_vec	orig;
	t_vec	orientation;
	float	fov;
}	t_cam;

typedef struct s_light
{
	t_vec	orig;
	float	ratio;
}	t_light;

typedef struct s_sphere
{
	t_vec			center;
	t_color			tint;
	float			radius;
	struct s_sphere	*prev;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_vec	point;
	t_vec	normal;
	t_color	tint;
	struct s_plane	*prev;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vec				center;
	t_vec				normal;
	t_color				tint;
	float				radius;
	float				height;
	struct s_cylinder	*prev;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_head
{
	t_ambient	*amb;
	t_cam		*cam;
	t_light		*light;
	t_sphere	*sphere;
	t_sphere	*begin_sphere;
	t_plane		*plane;
	t_plane		*begin_plane;
	t_cylinder	*cylin;
	t_cylinder	*begin_cylinder;
	int			coefficient;
}	t_head;////////////changeeeeeeeeeeee

typedef struct s_window
{
	int	width;
	int	height;
}	t_window;

void		exit_code(int code, char *msg);
void		parsing(int argc, char **argv, t_head *head);
void		checker_parsing(char **splitted_line, t_head *head);
//init.c
t_ambient	*init_ambient(float ratio, t_color tint);
t_cam		*init_cam(t_vec orig, t_vec orient, float fov);
t_light		*init_light(t_vec orig, float ratio);
t_sphere	*init_sphere(t_vec orig, t_color tint, float radius);
t_plane		*init_plane(t_vec point, t_vec normal, t_color tint);
t_cylinder	*init_cylinder(t_vec center, t_vec normal, t_color tint, float radius, float height);
//utils1.c
int			ft_double_len(char **str);
float 		ft_atof(char *str);
//is_in_set.c
int			is_in_set(char c);
int			ft_isspace(char c);
//main.c
void		init_head(t_head *head);
//checker_parsing.c
void		check_vector(char **vec_splitted, t_vec *vector, float lower_bound, float upper_bound);
//split_m.c
char		**ft_split_m(char const *s);
#endif