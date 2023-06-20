#include "minirt.h"

bool    intersect_sphere(t_ray ray, t_sphere sphere, t_cross *cross)
{
    float   tOHdot;
    float   tHC;
    float   dSquare;
    float   t;
    t_vec   L;

    L = vecSub(sphere.center, ray.orig);
    tOHdot = dotProduct(L, ray.dir);
    if (tOHdot < 0)
        return (false);
    dSquare = vecNorm(L) * vecNorm(L) - tOHdot * tOHdot;
    if (dSquare > sphere.radius * sphere.radius)
        return (false);
    tHC = sqrt(sphere.radius * sphere.radius - dSquare);
    cross->t = tOHdot - tHC;
    t = tOHdot + tHC;
    if (t < cross->t)
        cross->t = t;
    point_calc(&cross->p, ray, cross->t);
    cross->n = sphere_normal(cross->p, sphere.center);
    cross->color = sphere.tint;
    return (true);
}