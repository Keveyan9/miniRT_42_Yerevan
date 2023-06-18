#include "minirt.h"

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