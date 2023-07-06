#include "/Users/zkarapet/Desktop/newminirt/includes/minirt.h"

t_cross *loopSphereList(t_sphere *sphere, t_ray ray, float x, float y)
{
    t_sphere *head;
    t_cross *cross;
    float tNear;

    head = sphere;
    if (!head)
        return (NULL);
    tNear = INFINITY;
    cross = malloc(sizeof(t_cross));
    if (!cross)
        exit_code(1, "cross malloc failed");
    cross->t = 0;
    while (head)
    {
        if (intersectSphere(ray, *head, cross, x, y) && cross->t < tNear)
        {
            // printf("sphere intersected\n");
            tNear = cross->t;
        }
        head = head->next;
    }
    cross->t = tNear;
    // if (isinf(tNear))
    //     printf("inifnity\n");
    // else
    //     printf("tNear == %f\n", tNear);
    return (cross);
}

t_cross *loopPlaneList(t_plane *plane, t_ray ray)
{
    t_plane *head;
    t_cross *cross;
    float   tNear;

    head = plane;
    tNear = INFINITY;
    cross = malloc(sizeof(t_cross));
    if (!cross)
        exit_code(1, "cross malloc failed");
    cross->t = 0;
    while (head)
    {
        if (intersectPlane(ray, *head, cross) && cross->t < tNear)
            tNear = cross->t;
        head = head->next;
    }
    cross->t = tNear;
    return (cross);
}

t_cross *loopCylinList(t_cylinder *cylin, t_ray ray)
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
            tNear = cross->t;
        head = head->next;
    }
    cross->t = tNear;
    return (cross);
}

bool rayTrace(t_scene scene, t_ray ray, t_cross **finalCross, float x, float y)
{
    float tNear;
    t_cross *crossPlane;
    t_cross *crossSphere;
    t_cross *crossCylin;

    tNear = INFINITY;
    crossPlane = loopPlaneList(scene.plane, ray);
    crossCylin = loopCylinList(scene.cylin, ray);
    crossSphere = loopSphereList(scene.sphere, ray, x, y);
    tNear = findMin(crossPlane->t, crossSphere->t, crossCylin->t);
    // printf("infinity tNear == %f\n", tNear);
    if (tNear == crossPlane->t)
        *finalCross = crossPlane;
    if (tNear == crossSphere->t)
        *finalCross = crossSphere;
    else if (tNear == crossCylin->t)
        *finalCross = crossCylin;
    if (tNear != INFINITY)
        return (1);
    return (0);
}

int create_rgb(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

void render(t_scene scene, t_mlx *mlxData)
{
    int             x;
    int             y;
    unsigned int    color;
    t_ray           ray;
    t_cross         *finalCross;
    t_color         col;

    finalCross = malloc(sizeof(t_cross));
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            ray = rayGenerate(x, y, *(scene.cam));
            if (!rayTrace(scene, ray, &finalCross, x, y))
            {
                // printf("I am hereeee black oneeeeeee\n");
                color = create_rgb(0, 0, 0);
            }
            // printf("finalCross->t == %f\n", finalCross->t);
            // if (finalCross->t == INFINITY)
            // {
            //     color = create_rgb(0, 0, 0);
            // }
            else
            {
                col = final_lighting(scene, finalCross);
                color = makeIntFromRGB(col);
                // printf("RED ONEEE\n");
                // color = create_rgb(255, 0, 0);
            }
            my_mlx_pixel_put(mlxData, x, y, color);
        }
    }
    mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
}
