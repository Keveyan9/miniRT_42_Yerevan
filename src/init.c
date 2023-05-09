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
	camera->fov = fov;
	return (camera);
}

t_light	*init_light(t_vec *orig, float ratio)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	if (!light)
		exit_code(1, "origin malloc failed");
	light->orig = orig;
	light->ratio = ratio;
	return (light);
}

t_sphere	*init_sphere(t_vec *center, t_color *tint, float radius)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit_code(1, "sphere malloc failed");
	sphere->center = center;
	sphere->tint = tint;
	sphere->radius = radius;
	return (sphere);
}

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
	return (cylinder);
}