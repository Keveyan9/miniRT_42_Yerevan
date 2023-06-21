#include "minirt.h"

float   loopSphereList(t_sphere *sphere, t_ray ray)
{
    t_sphere    *head;
    float       tNear;
    float       t;

    head = sphere;
    tNear = INFINITY;
    while (head && head->next)
    {
        if (intersectSphere(ray, *head, &t) && t < tNear)
            tNear = t;
        head = head->next;
    }
    return (tNear);
}

float   loopPlaneList(t_plane *plane, t_ray ray)
{
    t_plane    *head;
    float       tNear;
    float       t;

    head = plane;
    tNear = INFINITY;
    while (head && head->next)
    {
        if (intersectPlane(ray, *head, &t) && t < tNear)
            tNear = t;
        head = head->next;
    }
    return (tNear);
}

float   loopCylinList(t_cylinder *cylin, t_ray ray)
{
    t_cylinder  *head;
    float       tNear;
    float       t;

    head = cylin;
    tNear = INFINITY;
    while (head && head->next)
    {
        if (intersectCylin(ray, *head, &t) && t < tNear)
            tNear = t;
        head = head->next;
    }
    return (tNear);
}

bool    rayTrace(t_scene scene, t_ray ray)
{
    float   tNear;

    tNear = INFINITY;
    
    //loop over all scene objects
    //intersection checking
    //tNear deciding
}

t_color    rayCast(t_ray ray)
{
    //rays from origin to x, y
    //color deciding
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