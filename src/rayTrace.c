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

bool    rayTrace(t_scene scene, t_ray ray, t_cross *finalCross)
{
    float   tNear;
    t_cross crossPlane;
    t_cross crossSphere;
    t_cross crossCylin;
    
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
    int     x;
    int     y;
    t_ray   ray;
    t_cross finalCross;

    x = -1;
    while (++x < WIDTH)
    {
        y = -1;
        while (++y < HEIGHT)
        {
            ray = rayGenerate(x, y);
            //raycast();
        }
    }
    //put image to window with mlx_put_image_to_window()
}