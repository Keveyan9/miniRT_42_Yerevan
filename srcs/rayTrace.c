
#include "minirt.h"

t_cross   *loopSphereList(t_sphere *sphere, t_ray ray)
{
    t_sphere    *head;
    t_cross     *cross;
    float       tNear;

    head = sphere;
    tNear = INFINITY;
    cross = malloc(sizeof(t_cross));
    if (!cross)
        exit_code(1, "cross malloc failed");
    cross->t = 0;
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
    if (!cross)
        exit_code(1, "cross malloc failed");
    cross->t = 0;
    while (head)
    {
        if (intersectPlane(ray, *head, cross) && cross->t < tNear)
        {
           // printf("Hereeee\n");
            tNear = cross->t;
        }
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
    if (!cross)
        exit_code(1, "cross malloc failed");
    cross->t = 0;
    while (head)
    {
        if (intersectCylin(ray, *head, cross) && cross->t < tNear)
        {
            tNear = cross->t;
        }
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
        *finalCross = crossPlane;
    else if (tNear == crossSphere->t)
        *finalCross = crossSphere;
    else if (tNear == crossCylin->t)
        *finalCross = crossCylin;
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
    t_color         col;

    finalCross = malloc(sizeof(t_cross));
    x = -1;
    while (++x < WIDTH)
    {
        y = -1;
        while (++y < HEIGHT)
        {
            ray = rayGenerate(x, y, *(scene.cam));
            rayTrace(scene, ray, &finalCross);
            if (finalCross->t == INFINITY)
                color = create_rgb(0,0,0);
            else
            {
               // printf("aaaa here\n");
                col = final_lighting(scene, finalCross);
               // printf("col  r == %f, g == %f, b === %f\n", col.r, col.g, col.b);
                color = makeIntFromRGB(col);
            }
            my_mlx_pixel_put(mlxData, x, y, color);
        }
    }
    mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
}
