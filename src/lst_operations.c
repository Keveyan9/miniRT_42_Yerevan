#include "minirt.h"

void    init_head(t_head *head)
{
    head->amb = NULL;
    head->cam = NULL;
    head->light = NULL;
    head->sphere = NULL;
    head->begin_sphere = NULL;
    head->plane = NULL;
    head->begin_plane = NULL;
    head->cylin = NULL;
    head->begin_cylinder = NULL;
    head->cofficient = 0;
}