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

t_cam *init_cam(float orient[3], int origin[3], float fov)
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
	camera->fov = fov;
	return (camera);
}

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
	light->ratio = ratio;
	return (light);
}

t_sphere *init_sphere(float center[3], int tint[3], float radius)
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
	sphere->radius = radius;
	return (sphere);
}

t_plane *init_plane(float point[3], float normal[3], int tint[3])
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

t_cylinder *init_cylinder(float center[3], float normal[3], int tint[3], float radius, float height)
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
	return (cylinder);
}