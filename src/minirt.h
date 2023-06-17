#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "scene.h"
# include "mlx.h"
# include "vectorRay.h"

# define WIDTH 1600
# define HEIGHT 900

typedef struct s_window
{
	int	width;
	int	height;
}	t_window;

void		exit_code(int code, char *msg);
void		parsing(int argc, char **argv, t_scene *scene);
int			checker_parsing(char **splitted_line, t_scene *scene);
//init.c
t_ambient	*initAmbient(float ratio, t_color tint);
t_cam		*initCam(t_vec orig, t_vec orient, float fov);
t_light		*initLight(t_vec orig, float ratio);
t_sphere	*initSphere(t_vec orig, t_color tint, float radius);
t_plane		*initPlane(t_vec point, t_vec normal, t_color tint);
t_cylinder	*initCylinder(t_vec center, t_vec normal, t_color tint, float radius, float height);
//utils1.c
int			ft_double_len(char **str);
float 		ft_atof(char *str);
bool		isInRangeCheck(float number, float lower, float upper);
//isInSet.c
int			isInSet(char c);
int			ft_isspace(char c);
//main.c
void		init_scene(t_scene *scene);
//checker_parsing.c
void		checkVector(char **vec_splitted, t_vec *vector, float lower_bound, float upper_bound);
//split_m.c
char		**ft_split_m(char const *s);
//checkerUtils.c
int			only_digit_in_str(char *s);
int			color_range_check(t_color *tint);
int 		vector_range_check(t_vec *vector, float lower_bound, float upper_bound);
//objectsInit.c
void		initVector(t_vec vector, t_vec *objVect);
void		initColor(t_color tint, t_color *ambTint);
t_ambient	*initAmbient(float ratio, t_color tint);
t_cam		*initCam(t_vec origin, t_vec orient, float fov);
t_light		*initLight(t_vec orig, float ratio);
//checkers.c
void		checkVector(char **vec_splitted, t_vec *vector, float lower_bound, float upper_bound);
void		checkColor(char **vec_splitted, t_color *tint);
void		checker_C(char **splitted_C, t_scene *scene);
void		checker_L(char **splitted_L, t_scene *scene);
void		checker_A(char **splitted_A, t_scene *scene);
void		checkerPl(char **splitted_pl, t_scene *scene);
void		checkerSp(char **splitted_sp, t_scene *scene);
void		checkerCy(char **splitted_cy, t_scene *scene);
//intersections
bool		intersectPlane(t_ray ray, t_plane plane, float *t);
bool		intersect_sphere(t_ray ray, t_sphere sphere, float *t0, float *t1);

#endif