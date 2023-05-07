#include "../includes/minirt.h"

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