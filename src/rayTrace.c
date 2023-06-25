#include "minirt.h"

t_cross   loopSphereList(t_sphere *sphere, t_ray ray)
{
    t_sphere    *head;
    t_cross     cross;
    float       tNear;

    head = sphere;
    tNear = INFINITY;
    cross.t = 0;
    while (head && head->next)
    {
        if (intersectSphere(ray, *head, &cross) && cross.t < tNear)
            tNear = cross.t;
        head = head->next;
    }
    cross.t = tNear;
    cross.type = SPHERE;
    return (cross);
}

t_cross   loopPlaneList(t_plane *plane, t_ray ray)
{
    t_plane    *head;
    t_cross     cross;
    float       tNear;

    head = plane;
    tNear = INFINITY;
    cross.t = 0;
    while (head && head->next)
    {
        if (intersectPlane(ray, *head, &cross) && cross.t < tNear)
            tNear = cross.t;
        head = head->next;
    }
    cross.t = tNear;
    cross.type = PLANE;
    return (cross);
}

t_cross   loopCylinList(t_cylinder *cylin, t_ray ray)
{
    t_cylinder  *head;
    t_cross     cross;
    float       tNear;

    head = cylin;
    tNear = INFINITY;
    cross.t = 0;
    while (head && head->next)
    {
        if (intersectCylin(ray, *head, &cross) && cross.t < tNear)
            tNear = cross.t;
        head = head->next;
    }
    cross.t = tNear;
    cross.type = CYLIN;
    return (cross);
}

bool    rayTrace(t_scene scene, t_ray ray)
{
    float   tNear;
    float   tsp;
    float   tpl;
    float   tcy;
    
    //loop over all scene objects
    //intersection checking
    //tNear deciding
    tcy = loopPlaneList(scene.plane, ray).t;
    tpl = loopCylinList(scene.cylin, ray).t;
    tsp = loopSphereList(scene.sphere, ray).t;
    tNear = findMin(tcy, tpl, tsp);
    if (tNear != INFINITY)
        return (1);
    return (0);
}

void    render()//, t_mlx mlxData)
{
    t_ray   ray;
    int     x;
    int     y;

    x = -1;
    y = -1;
    while (++x < WIDTH)
    {
        y = -1;
        while (++y < HEIGHT)
        {
            ray = rayGenerate(x, y);
            //raycast();
        }
    }
}