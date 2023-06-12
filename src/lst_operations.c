#include "minirt.h"

void    init_scene(t_scene *scene)
{
    scene->amb = NULL;
    scene->cam = NULL;
    scene->light = NULL;
    scene->sphere = NULL;
    scene->begin_sphere = NULL;
    scene->plane = NULL;
    scene->begin_plane = NULL;
    scene->cylin = NULL;
    scene->begin_cylinder = NULL;
    scene->coefficient = 0;
}
