#include "minirt.h"

bool    intersectPlane(t_ray ray, t_plane plane, t_cross *cross)
{
    float   denominator;

    denominator = dotProduct(ray.dir, plane.normal);
    if (denominator < 1e-6)
        return (false);
    cross->t = (dotProduct(vecSub(plane.point, ray.orig), plane.normal))
            / denominator;
    cross->n = plane.normal;
    cross_point(&cross->p, ray, cross->t);
    return (true);
}