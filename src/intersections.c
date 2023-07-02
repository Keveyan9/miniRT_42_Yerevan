#include "minirt.h"

void    print_vec(t_vec vec, char *msg)
{
    printf("%s vec.x == %f\n", msg, vec.x);
    printf("%s vec.y == %f\n", msg, vec.y);
    printf("%s vec.z == %f\n", msg, vec.z);
}

bool    intersectCylin(t_ray ray, t_cylinder cylin, t_cross *cross)
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
    // print_vec(ray.orig, "ray origin is  ");
    // print_vec(V, "V is  ");
    t = dotProduct(V, ray.dir) / dotProduct(ray.dir, ray.dir);
    point_calc(&P, ray, t);
    //P = vecAdd(ray.orig, vecScale(t, ray.dir));
    Q = vecSub(P, cylin.center);
    d = dotProduct(Q, cylin.axis);
    U = vecSub(Q, vecScale(d, cylin.axis));
    // printf("intersect cylin == %f\n", d);
    if (isInRangeCheck(d, -cylin.height/2, cylin.height/2))// && vecNorm(U) <= cylin.radius)
    {
        cross->t = t;
        cross->p = P;
        cross->n = cylinder_normal(cylin, cross->p);
        cross->color = cylin.tint;
        return (true);
    }
    return (false);
}

bool    intersectSphere(t_ray ray, t_sphere sphere, t_cross *cross)
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
    cross->t = t0;
    point_calc(&cross->p, ray, cross->t);
    cross->n = sphere_normal(cross->p, sphere.center);
    cross->color = sphere.tint;
    return (true);
}

bool    intersectPlane(t_ray ray, t_plane plane, t_cross *cross)
{
    float   denominator;

    denominator = dotProduct(plane.normal, ray.dir);
    if (fabs(denominator) < 1e-6)
        return (false);
    cross->t = (dotProduct(vecSub(plane.point, ray.orig), plane.normal))
            / denominator;
    point_calc(&cross->p, ray, cross->t);
   // printf("cross p == %f, y == %f, z === %f\n", cross->p.x, cross->p.y, cross->p.z);
    cross->n = plane.normal;
    cross->color = plane.tint;
    return (true);
}