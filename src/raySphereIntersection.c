#include "minirt.h"

bool intersect_sphere(t_ray ray, t_sphere sphere, float *t0, float *t1)
{
    float   tOHdot;
    float   tHC;
    float   dSquare;
    t_vec   L;

    L = vecSub(sphere.center, ray.orig);
    tOHdot = dotProduct(L, ray.dir);
    if (tOHdot < 0)
        return (false);
    dSquare = vecNorm(L) * vecNorm(L) - tOHdot * tOHdot;
    if (dSquare > sphere.radius * sphere.radius)
        return (false);
    tHC = sqrt(sphere.radius * sphere.radius - dSquare);
    *t0 = tOHdot - tHC;
    *t1 = tOHdot + tHC;
    return (true);
}