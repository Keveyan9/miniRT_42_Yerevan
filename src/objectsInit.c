#include "minirt.h"

void	initVector(t_vec vector, t_vec *objVect)
{
	(*objVect).x = vector.x;
	(*objVect).y = vector.y;
	(*objVect).z = vector.z;
}

void	initColor(t_color tint, t_color *ambTint)
{
	(*ambTint).r = tint.r;
	(*ambTint).g = tint.g;
	(*ambTint).b = tint.b;
}

t_ambient	*initAmbient(float ratio, t_color tint)
{
	t_ambient *amb;
	int i;

	i = -1;
	amb = malloc(sizeof(t_ambient));
	if (!amb)
		exit_code(1, "ambient malloc failed");
	initColor(tint, &(amb->tint));
	amb->ratio = ratio;
	return (amb);
}

t_cam	*initCam(t_vec origin, t_vec orient, float fov)
{
	t_cam *camera;
	int i;

	i = -1;
	camera = malloc(sizeof(t_cam));
	if (!camera)
		exit_code(1, "camera malloc failed");
	initVector(origin, &(camera->orig));
	initVector(orient, &(camera->orientation));
	camera->fov = fov;
	return (camera);
}

t_light	*initLight(t_vec orig, float ratio, t_color tint)
{
	t_light *light;
	int i;

	i = -1;
	light = malloc(sizeof(t_light));
	if (!light)
		exit_code(1, "origin malloc failed");
	initVector(orig, &(light->orig));
	initColor(tint, &(light->tint));
	light->ratio = ratio;
	return (light);
}