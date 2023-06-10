#include "minirt.h"

void	init_vector(t_vec vector, t_vec *objVect)
{
	(*objVect).x = vector.x;
	(*objVect).y = vector.y;
	(*objVect).z = vector.z;
}

void	init_color(t_color tint, t_color *ambTint)
{
	(*ambTint).r = tint.r;
	(*ambTint).g = tint.g;
	(*ambTint).b = tint.b;
}

t_ambient *init_ambient(float ratio, t_color tint)
{
	t_ambient *amb;
	int i;

	i = -1;
	amb = malloc(sizeof(t_ambient));
	if (!amb)
		exit_code(1, "ambient malloc failed");
	init_color(tint, &(amb->tint));
	amb->ratio = ratio;
	return (amb);
}

t_cam *init_cam(t_vec origin, t_vec orient, float fov)
{
	t_cam *camera;
	int i;

	i = -1;
	camera = malloc(sizeof(t_cam));
	if (!camera)
		exit_code(1, "camera malloc failed");
	init_vector(origin, &(camera->orig));
	init_vector(orient, &(camera->orientation));
	camera->fov = fov;
	return (camera);
}

t_light	*init_light(t_vec orig, float ratio)
{
	t_light *light;
	int i;

	i = -1;
	light = malloc(sizeof(t_light));
	if (!light)
		exit_code(1, "origin malloc failed");
	init_vector(orig, &(light->orig));
	light->ratio = ratio;
	return (light);
}

t_sphere	*init_sphere(t_vec orig, t_color tint, float radius)
{
	t_sphere *sphere;
	int i;

	i = -1;
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit_code(1, "sphere malloc failed");
	init_vector(orig, &(sphere->center));
	init_color(tint, &(sphere->tint));
	sphere->radius = radius;
	return (sphere);
}

t_plane	*init_plane(t_vec point, t_vec normal, t_color tint)
{
	t_plane *plane;
	int i;

	i = -1;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		exit_code(1, "plane malloc failed");
	init_vector(point, &(plane->point));
	init_vector(normal, &(plane->normal));
	init_color(tint, &(plane->tint));
	return (plane);
}

t_cylinder	*init_cylinder(t_vec center, t_vec normal, t_color tint, float radius, float height)
{
	t_cylinder *cylinder;
	int i;

	i = -1;
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit_code(1, "cylinder malloc failed");
	init_vector(center, &(cylinder->center));
	init_vector(normal, &(cylinder->normal));
	init_color(tint, &(cylinder->tint));
	cylinder->radius = radius;
	cylinder->height = height;
	return (cylinder);
}