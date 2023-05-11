#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# include <float.h>
# include "/root/minirt/lib/libft/libft.h"
# include "/root/minirt/lib/gnl/get_next_line.h"
# define SPLIT_SET	" \t\v\b"

typedef struct s_ambient
{
	float	ratio;
	float	tint[3];
}	t_ambient;

typedef struct s_cam
{
	float	orig[3];
	float	orientation[3];
	float	fov;
}	t_cam;

typedef struct s_light
{
	float	orig[3];
	float	ratio;
}	t_light;

typedef struct s_sphere
{
	float		center[3];
	float		tint[3];
	float		radius;
	struct s_sphere	*prev;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	float	point[3];
	float	normal[3];
	float	tint[3];
	struct s_plane	*prev;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	float		center[3];
	float		normal[3];
	float		radius;
	float		height;
	float		tint[3];
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
	int			cofficient;
	int			atof_flag;
}	t_head;

typedef struct s_window
{
	int	width;
	int	height;
}	t_window;

void		exit_code(int code, char *msg);
void		parsing(int argc, char **argv, t_head *head);
void		checker_parsing(char **splitted_line, t_head *head);
//init.c
t_ambient	*init_ambient(float ratio, float tint[3]);
t_cam		*init_cam(float orient[3], float origin[3], float fov);
t_light		*init_light(float orig[3], float ratio);
t_sphere	*init_sphere(float center[3], float tint[3], float radius);
t_plane		*init_plane(float point[3], float normal[3], float tint[3]);
t_cylinder	*init_cylinder(float center[3], float normal[3], float tint[3], float radius, float height);
//utils1.c
int			ft_double_len(char **str);
float 	ft_atof(char *str, t_head *head);
//is_in_set.c
int			is_in_set(char c);
int			ft_isspace(char c);
//main.c
void		init_head(t_head *head);
//checker_parsing.c
void		check_vector(char **vec_splitted, float (*vec)[3], float lower_bound, float upper_bound, t_head *);
//split_m.c
char	**ft_split_m(char const *s);
#endif