#include "minirt.h"

t_cross   *loopSphereList(t_sphere *sphere, t_ray ray)
{
    t_sphere    *head;
    t_cross     *cross;
    float       tNear;

    head = sphere;
    tNear = INFINITY;
    cross = malloc(sizeof(t_cross));
    cross->t = 0;
    if (!cross)
        return (NULL);
    while (head)
    {
        if (intersectSphere(ray, *head, cross) && cross->t < tNear)
            tNear = cross->t;
        head = head->next;
    }
    cross->t = tNear;
    cross->type = SPHERE;
    return (cross);
}

t_cross   *loopPlaneList(t_plane *plane, t_ray ray)
{
    t_plane    *head;
    t_cross     *cross;
    float       tNear;

    head = plane;
    tNear = INFINITY;
    cross = malloc(sizeof(t_cross));
    cross->t = 0;
    if (!cross)
        return (NULL);
    while (head)
    {
        if (intersectPlane(ray, *head, cross) && cross->t < tNear)
            tNear = cross->t;
        head = head->next;
    }
    cross->t = tNear;
    cross->type = PLANE;
    return (cross);
}

t_cross   *loopCylinList(t_cylinder *cylin, t_ray ray)
{
    t_cylinder  *head;
    t_cross     *cross;
    float       tNear;

    head = cylin;
    tNear = INFINITY;
    cross = malloc(sizeof(t_cross));
    cross->t = 0;
    if (!cross)
        return (NULL);
    while (head)
    {
        if (intersectCylin(ray, *head, cross) && cross->t < tNear)
            tNear = cross->t;
        head = head->next;
    }
    cross->t = tNear;
    cross->type = CYLIN;
    return (cross);
}

bool    rayTrace(t_scene scene, t_ray ray, t_cross **finalCross)
{
    float   tNear;
    t_cross *crossPlane;
    t_cross *crossSphere;
    t_cross *crossCylin;
    
    tNear = INFINITY;
    crossPlane = loopPlaneList(scene.plane, ray);
    crossCylin = loopCylinList(scene.cylin, ray);
    crossSphere = loopSphereList(scene.sphere, ray);
    tNear = findMin(crossPlane->t, crossSphere->t, crossCylin->t);
    if (tNear == crossPlane->t)
    {
        *finalCross = crossPlane;
    }
    else if (tNear == crossSphere->t)
    {
        *finalCross = crossSphere;
    }
    else if (tNear == crossCylin->t)
    {
        *finalCross = crossCylin;
    }
    if (tNear != INFINITY)
        return (1);
    return (0);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void    render(t_scene scene, t_mlx *mlxData)
{
    int             x;
    int             y;
    unsigned int    color;
    t_ray           ray;
    t_cross         *finalCross;


    finalCross = malloc(sizeof(t_cross));
    x = -1;
    while (++x < WIDTH)
    {
        y = -1;
        while (++y < HEIGHT)
        {
            ray = rayGenerate(x, y);
            rayTrace(scene, ray, &finalCross);
            color = makeIntFromRGB(final_lighting(scene, finalCross, 0.5, 32));
            if (finalCross->t == INFINITY)
                color = create_rgb(0,0,0);
            else
                color = makeIntFromRGB(final_lighting(scene, finalCross, 0.5, 32));
        }
    }
    mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
}