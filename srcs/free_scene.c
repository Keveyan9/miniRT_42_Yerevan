#include"minirt.h"

void free_scene(t_scene *s)
{
	
	if(s->amb)
		free(s->amb);
	if(s->cam)
		free(s->cam);
	if(s->light)
		free(s->light);
	if(s->sphere)
		free(s->sphere);
	if(s->begin_sphere)
		free(s->begin_sphere);
	if(s->plane)
		free(s->plane);
	if(s->begin_plane)
		free(s->begin_plane);
	if(s->cylin)
		free(s->cylin);
	if(s->begin_cylinder)
		free(s->begin_cylinder);
}