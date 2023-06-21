#include "minirt.h"

bool    intersectCylin(t_ray ray, t_cylinder cylin, float *tNear)
{
    t_vec   V;//vector from ray origin to the cylinder center
    float   t;//projection of V onto ray direction D
    t_vec   P;//closest point on the ray to the cylinder's center P = O + t * D
    t_vec   Q;//the vector from the closest point on the ray to the cylin center, P - C
    float   d;//dot product of the vector Q on A, A is the axis vector of cylinder
    t_vec   U;//Q - d*A
    //d*A is a vector along cylinder's axis, which is the projection of Q along the axis
    //-d*A is d*A vector opposite to y axis, because we need to calculate U = Q - d*A, to know if ||U|| <= r, for that we should put Q and d*A from exact same point
    //In short, if the closest point is within the height and radius, there is an intersection with the finite cylinder.

    V = vecSub(ray.orig, cylin.center);
    t = dotProduct(V, ray.dir) / dotProduct(ray.dir, ray.dir);
    point_calc(&P, ray, t);
    //P = vecAdd(ray.orig, vecScale(t, ray.dir));
    Q = vecSub(P, cylin.center);
    d = dotProduct(Q, cylin.axis);
    U = vecSub(Q, vecScale(d, cylin.axis));
    if (isInRangeCheck(d, -HEIGHT/2, HEIGHT/2) && vecNorm(U) <= cylin.radius)
    {
        *tNear = t;
        return (true);
    }
    return (false);
}

bool    intersectSphere(t_ray ray, t_sphere sphere, float *t)
{
    float   tOHdot;
    float   tHC;
    float   dSquare;
    float   t0;
    float   t1;
    t_vec   L;

    L = vecSub(sphere.center, ray.orig);
    tOHdot = dotProduct(L, ray.dir);
    if (tOHdot < 0)
        return (false);
    dSquare = vecNorm(L) * vecNorm(L) - tOHdot * tOHdot;
    if (dSquare > sphere.radius * sphere.radius)
        return (false);
    tHC = sqrt(sphere.radius * sphere.radius - dSquare);
    t0 = tOHdot - tHC;
    t1 = tOHdot + tHC;
    if (t0 > t1)
        swap(&t0, &t1);
    if (t0 < 0)
    {
        t0 = t1;
        if (t0 < 0)
            return (false);
    }
    *t = t0;
    return (true);
}

bool    intersectPlane(t_ray ray, t_plane plane, float *t)
{
    float   denominator;

    denominator = dotProduct(ray.dir, plane.normal);
    if (denominator < 1e-6)
        return (false);
    *t = (dotProduct(vecSub(plane.point, ray.orig), plane.normal))
            / denominator;
    return (true);
}