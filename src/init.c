<<<<<<< HEAD
#include "../include/minirt.h"

t_vec	*init_vector(float x, float y, float z)
{
	t_vec *vector;

	vector = malloc(sizeof(t_vec));
	if (!vector)
		exit_code(1, "vector malloc failed");
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_color	*init_color(float r, float g, float b)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	if (!color)
		exit_code(1, "color malloc failed");
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_cam	*init_cam(t_vec *orient, t_vec *orig, float fov)
{
	t_cam *camera;

	camera = malloc(sizeof(t_cam));
	if (!camera)
		exit_code(1, "camera malloc failed");
	camera->orientation = orient;
	camera->orig = orig;
=======
#include "minirt.h"

// t_vec	*init_vector(float x, float y, float z)
// {
// 	t_vec *vector;

// 	vector = malloc(sizeof(t_vec));
// 	if (!vector)
// 		exit_code(1, "vector malloc failed");
// 	vector->x = x;
// 	vector->y = y;
// 	vector->z = z;
// 	return (vector);
// }

// t_color	*init_color(float r, float g, float b)
// {
// 	t_color *color;

// 	color = malloc(sizeof(t_color));
// 	if (!color)
// 		exit_code(1, "color malloc failed");
// 	color->r = r;
// 	color->g = g;
// 	color->b = b;
// 	return (color);
// }

t_ambient *init_ambient(float ratio, float tint[3])
{
	t_ambient *amb;
	int i;

	i = -1;
	amb = malloc(sizeof(t_ambient));
	if (!amb)
		exit_code(1, "ambient malloc failed");
	while (++i < 3)
		amb->tint[i] = tint[i];
	amb->ratio = ratio;
	return (amb);
}

t_cam *init_cam(float orient[3],float origin[3], float fov)
{
	t_cam *camera;
	int i;

	i = -1;
	camera = malloc(sizeof(t_cam));
	if (!camera)
		exit_code(1, "camera malloc failed");
	while (++i < 3)
	{
		camera->orientation[i] = orient[i];
		camera->orig[i] = origin[i];
	}
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
	camera->fov = fov;
	return (camera);
}

<<<<<<< HEAD
t_light	*init_light(t_vec *orig, float ratio)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	if (!light)
		exit_code(1, "origin malloc failed");
	light->orig = orig;
=======
t_light *init_light(float orig[3], float ratio)
{
	t_light *light;
	int i;

	i = -1;
	light = malloc(sizeof(t_light));
	if (!light)
		exit_code(1, "origin malloc failed");
	while (++i < 3)
		light->orig[i] = orig[i];
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
	light->ratio = ratio;
	return (light);
}

<<<<<<< HEAD
t_sphere	*init_sphere(t_vec *center, t_color *tint, float radius)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit_code(1, "sphere malloc failed");
	sphere->center = center;
	sphere->tint = tint;
=======
t_sphere *init_sphere(float center[3], float tint[3], float radius)
{
	t_sphere *sphere;
	int i;

	i = -1;
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit_code(1, "sphere malloc failed");
	while (++i < 3)
	{
		sphere->center[i] = center[i];
		sphere->tint[i] = tint[i];
	}
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
	sphere->radius = radius;
	return (sphere);
}

<<<<<<< HEAD
t_plane	*init_plane(t_vec *point, t_vec *normal, t_color *tint)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		exit_code(1, "plane malloc failed");
	plane->point = point;
	plane->normal = normal;
	plane->tint = tint;
	return (plane);
}

t_cylinder	*init_cylinder(t_vec *center, t_vec *normal, float radius, float height, t_color *tint)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit_code(1, "cylinder malloc failed");
	cylinder->center = center;
	cylinder->normal = normal;
	cylinder->radius = radius;
	cylinder->height = height;
	cylinder->tint = tint;
=======
t_plane *init_plane(float point[3], float normal[3], float tint[3])
{
	t_plane *plane;
	int i;

	i = -1;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		exit_code(1, "plane malloc failed");
	while (++i < 3)
	{
		plane->point[i] = point[i];
		plane->normal[i] = normal[i];
		plane->tint[i] = tint[i];
	}
	return (plane);
}

t_cylinder *init_cylinder(float center[3], float normal[3], float tint[3], float radius, float height)
{
	t_cylinder *cylinder;
	int i;

	i = -1;
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit_code(1, "cylinder malloc failed");
	while (++i < 3)
	{
		cylinder->center[i] = center[i];
		cylinder->normal[i] = normal[i];
		cylinder->tint[i] = tint[i];
	}
	cylinder->radius = radius;
	cylinder->height = height;
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
	return (cylinder);
}