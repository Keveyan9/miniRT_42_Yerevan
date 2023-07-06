#include "minirt.h"

float solveQuadratic(float a, float b, float c)
{
    float t0;
    float t1;
    float D;

    D = b * b - 4 * a * c;
    if (D < 0)
        return (-1);
    else if (D == 0)
        return (-b / (2 * a));
    else
    {
        t0 = (-b + sqrt(D)) / 2 * a;
        t1 = (-b - sqrt(D)) / 2 * a;
        if (t0 > t1)
            swap(&t0, &t1);
        if (t0 < 0)
        {
            t0 = t1;
            if (t0 < 0)
                return (-1);
        }
    }
    return (t0);
}

t_vec cylinder_normal2(t_cylinder cylin, t_cross cross, float m)
{
    t_vec norm;

    norm = normalize(vecSub(vecSub(cross.p, topCapCenter(cylin)), vecScale(m, cylin.axis)));
    return (norm);
}

bool intersectInfiniteCylin(t_ray ray, t_cylinder cylin, t_cross *cross)
{
    t_vec X;
    float a;
    float b;
    float c;
    float m;

    cylin.topCapCent = topCapCenter(cylin);
    X = vecSub(ray.orig, cylin.topCapCent);
    a = dotProduct(ray.dir, ray.dir) - pow(dotProduct(ray.dir, cylin.axis), 2);
    c = dotProduct(X, X) - pow(dotProduct(X, cylin.axis), 2) - cylin.radius * cylin.radius;
    b = 2 * (dotProduct(ray.dir, X) - dotProduct(ray.dir, cylin.axis) * dotProduct(X, cylin.axis));
    cross->t = solveQuadratic(a, b, c);
    if (cross->t < 0)
        return (false);
    point_calc(&cross->p, ray, cross->t);
    m = dotProduct(ray.dir, cylin.axis) * cross->t + dotProduct(X, cylin.axis);
    if (m < 0 || m > cylin.height)
        return (false);
    cross->n = cylinder_normal2(cylin, *cross, m);
    cross->color = cylin.tint;
    return (true);
}

bool intersectCylin2(t_ray ray, t_cylinder cylin, t_cross *cross)
{
    t_plane plane;
    t_cross crossPlane;
    t_vec   hitPoint;
    float   t;

    t = INFINITY;
    plane.point = cylin.topCapCent;
    plane.normal = vecInverse(cylin.axis);
    if (intersectPlane(ray, plane, &crossPlane))
    {
        // printf("intersect plane 111111\n");
        point_calc(&hitPoint, ray, crossPlane.t);
        if (vecNorm(vecSub(hitPoint, cylin.topCapCent)) <= cylin.radius * cylin.radius && crossPlane.t < t)
            t = crossPlane.t;
    }
    plane.point = bottomCapCenter(cylin);
    if (intersectPlane(ray, plane, &crossPlane))
    {
        // printf("intersect plane 222222\n");
        point_calc(&hitPoint, ray, crossPlane.t);
        if (vecNorm(vecSub(hitPoint, cylin.topCapCent)) <= cylin.radius * cylin.radius && crossPlane.t < t)
            t = crossPlane.t;
    }
    if (intersectInfiniteCylin(ray, cylin, cross) && cross->t < t)
        t = cross->t;
    return (t < INFINITY && t > 1e-6);
}