
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:12:09 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/05 19:12:16 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "../lib/minilibx_opengl/mlx.h"
# include "../lib/libft/libft.h"
# include "get_next_line.h"
# include "scene.h"
# include "mymlx.h"
# include "vectorRay.h"

# define WIDTH 1280
# define HEIGHT 720
# define FOCAL_DIST 0.5
# define STRENGTH 0.5
# define SHININESS 32

typedef	struct s_matrix
{
	t_vec	right;
	t_vec	up;
	t_vec	forward;
}	t_matrix;

typedef struct s_cross
{
	t_vec				n;
	t_vec				p;
	float				t;
	t_color				color;
}	t_cross;

void			exit_code(int code, char *msg, t_scene *scene, char **string);
void			parsing(int argc, char **argv, t_scene *scene);
void			print_vec(t_vec vec, char *msg);
//utils1.c
int				ft_double_len(char **str);
float			ft_atof(char *str);
bool			isInRangeCheck(float number, float lower, float upper);
void			swap(float	*a, float *b);
float			findMin(float a, float b, float c);
//isInSet.c
int				isInSet(char c);
int				ft_isspace(char c);
//main.c
void			init_scene(t_scene *scene);
//split_m.c
char			**ft_split_m(char const *s);
//checkerUtils.c
int				only_digit_in_str(char *s);
int				color_range_check(t_color *tint);
int				vector_norm_check(t_vec *vector);
int				vector_range_check(t_vec *vector, \
				float lower_bound, float upper_bound);
//objectsInit.c
void			initVector(t_vec vector, t_vec *objVect);
void			initColor(t_color tint, t_color *ambTint);
t_ambient		*initAmbient(float ratio, t_color tint, t_scene *scene);
t_cam			*initCam(t_vec origin, t_vec orient, float fov, t_scene *scene);
t_light			*initLight(t_vec orig, float ratio, \
					t_color tint, t_scene *scene);
//checkers.c
void			checkVector(char **vec_splitted, t_vec *vector, \
				float lower_bound, float upper_bound, t_scene *scene);
void			checkColor(char **vec_splitted, t_color *tint, t_scene *scene);
void			checker_C(char **splitted_C, t_scene *scene);
void			checker_L(char **splitted_L, t_scene *scene);
void			checker_A(char **splitted_A, t_scene *scene);
void			checkerPl(char **splitted_pl, t_scene *scene);
void			checkerSp(char **splitted_sp, t_scene *scene);
void			checkerCy(char **splitted_cy, t_scene *scene);
//intersections
bool			intersectPlane(t_ray ray, t_plane plane, t_cross *cross);
bool			intersectSphere(t_ray ray, t_sphere sphere, t_cross *cross);
bool			intersectCylin(t_ray ray, t_cylinder cylin, t_cross *cross);
//ray.c
t_ray			rayGenerate(float x, float y, t_cam camera);

// light.c
t_color			ambient_lighting(t_ambient *ambient);
t_color			diffuse_lighting(t_light *light, t_cross *cross);
t_color			specular_lightning(t_scene *scene, t_cross *cross);
bool			shadow(t_cross *cross, t_scene *scene);
t_color			final_lighting(t_scene *scene, t_cross *cross);

// light_utils.c
t_color			colorMul(t_color c, float f);
t_color			init_color(float r, float g, float b);
t_vec			reflect_vec(t_vec l, t_vec n);
void			point_calc(t_vec *p, t_ray r, float t);
t_color			final_color(t_cross *cross, t_color amb, \
					t_color diff, t_color spec);

//normal.c
t_vec			sphere_normal(t_vec p, t_vec center);
t_vec			topCapCenter(t_cylinder cyl);
t_vec			bottomCapCenter(t_cylinder cyl);
t_vec			cylinder_normal(t_cylinder cyl, t_vec p);


void			render(t_scene *scene, t_mlx *mlxData);

//colorOperations.c
unsigned int	makeIntFromRGB(t_color color);
t_color			makeRGBfromInt(unsigned int color);

//mlxFunctions.c
void			my_mlx_pixel_put(t_mlx *data, \
					double x, double y, unsigned int color);
void			mlxInit(t_mlx *mlxData);

//LookAt.c
void			LookAt(t_matrix *matrix, t_cam camera);

//rayTrace
bool			rayTrace(t_scene *scene, t_ray ray, t_cross **finalCross);

///cline
void			free_scene(t_scene *s);
#endif
