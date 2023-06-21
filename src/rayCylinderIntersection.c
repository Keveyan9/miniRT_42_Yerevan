#include "minirt.h"

int solveDiscriminant(float a, float b, float c)
{
    float   D;
    float   t1;
    float   t2;

    D = sqrt(b*b - 4 *a*c);
    if (D < 0)
        return (-1);
    else if (D == 0)
        return (-b/(2*a));
    t1 = (-b - D)/2*a;
    t2 = (-b + D)/2*a;
}

bool    intersectCylin(t_ray ray, t_cylinder cylin, t_cross *cross, float x, float y)
{
    t_vec   V;//vector from ray origin to the cylinder center
    float   t;//projection of V onto ray direction D
    t_vec   P;//closest point on the ray to the cylinder's center P = O + t * D
    t_vec   Q;//the vector from the closest point on the ray to the cylin center, P - C
    float   d;//dot product of the vector G on A, A is the axis vector of cylinder
    t_vec   U;
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
        cross->t = t;
        //TODO cylinder normal vector
        cross->p = P;
        return (true);
    }
    return (false);
}