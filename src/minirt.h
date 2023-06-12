#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# include <float.h>
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "scene.h"
# include "mlx.h"
# include "vectorRay.h"

typedef struct s_window
{
	int	width;
	int	height;
}	t_window;

void		exit_code(int code, char *msg);
void		parsing(int argc, char **argv, t_scene *scene);
int			checker_parsing(char **splitted_line, t_scene *scene);
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
void		init_scene(t_scene *scene);
//checker_parsing.c
void		check_vector(char **vec_splitted, t_vec *vector, float lower_bound, float upper_bound);
//split_m.c
char		**ft_split_m(char const *s);
#endif
