#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include "../lib/minilibx_opengl_20191021/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "scene.h"
# include "myMlx.h"
# include "vectorRay.h"

# define WIDTH 1600
# define HEIGHT 900

enum    objectType
{
    SPHERE,
    PLANE,
    CYLIN,
    noType
};

typedef struct s_cross
{
	t_vec	        n;
	t_vec	        p;
	float           t;
	t_color         color;
	enum objectType type;
}	t_cross;

void		exit_code(int code, char *msg);
void		parsing(int argc, char **argv, t_scene *scene);
int			checker_parsing(char **splitted_line, t_scene *scene);

//utils1.c
int			ft_double_len(char **str);
float 		ft_atof(char *str);
bool		isInRangeCheck(float number, float lower, float upper);
void		swap(float	*a, float *b);
float		findMin(float a, float b, float c);
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
t_light		*initLight(t_vec orig, float ratio, t_color tint);
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
bool		intersectPlane(t_ray ray, t_plane plane, t_cross *cross);
bool		intersectSphere(t_ray ray, t_sphere sphere, t_cross *cross);
bool		intersectCylin(t_ray ray, t_cylinder cylin, t_cross *cross);
//ray.c
t_ray		rayGenerate(float x, float y);//t_matrix lookAt

// light.c
t_color		ambient_lighting(t_ambient *ambient);
t_color		diffuse_lighting(t_light *light, t_cross *cross);
t_color		specular_lightning(t_scene scene, t_cross *cross, float strength, float s);
bool		shadow(t_cross cross, t_scene scene);
t_color		final_lighting(t_scene scene, t_cross cross, float strength, float s);

// light_utils.c
t_color		colorMul(t_color c, float f);
t_color		init_color(float r, float g, float b);
t_vec		reflect_vec(t_vec l, t_vec n);
void		point_calc(t_vec *p, t_ray r, float t);
t_color		final_color(t_light *light, t_color amb, t_color diff, t_color spec);

//normal.c
t_vec		sphere_normal(t_vec p, t_vec center);
void		topCapCenter(t_vec *top, t_cylinder cyl);
void		bottomCapCenter(t_vec *bottom, t_cylinder cyl);
t_vec		cylinder_normal(t_cylinder cyl, t_vec p);


//rayTrace
bool    		rayTrace(t_scene scene, t_ray ray, t_cross *finalCross);
t_color			colorMul(t_color c, float f);
t_color			init_color(float r, float g, float b);
t_vec			sphere_normal(t_vec p, t_vec center);
t_vec			reflect_vec(t_vec l, t_vec n);
void			point_calc(t_vec *p, t_ray r, float t);
t_color			final_color(t_light *light, t_color amb, t_color diff, t_color spec);
void			render(t_scene scene, t_mlx *mlxData);

//colorOperations.c
unsigned int	makeIntFromRGB(t_color color);
t_color			makeRGBfromInt(unsigned int color);

//normal.c
t_vec		sphere_normal(t_vec p, t_vec center);
void		topCapCenter(t_vec *top, t_cylinder cyl);
void		bottomCapCenter(t_vec *bottom, t_cylinder cyl);
t_vec		cylinder_normal(t_cylinder cyl, t_vec p);


//rayTrace
bool    	rayTrace(t_scene scene, t_ray ray, t_cross *finalCross);
#endif