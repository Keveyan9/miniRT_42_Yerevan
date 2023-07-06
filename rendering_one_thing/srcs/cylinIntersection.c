#include "minirt.h"

t_vec topCapCenter1(t_cylinder cyl)
{
 t_vec top;

 top.x = cyl.center.x;
    top.y = cyl.center.y + cyl.height / 2;
    top.z = cyl.center.z;
 return (top);
}

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

t_vec   cylinder_normal2(t_cylinder cylin, t_cross cross, float m)
{
    t_vec   norm;

    norm = normalize(vecSub(vecSub(cross.p, topCapCenter1(cylin)), vecScale(m, cylin.axis)));
    return (norm);
}

bool intersectCylin2(t_ray ray, t_cylinder cylin, t_cross *cross)
{
    t_vec X;
    float a;
    float b;
    float c;
    float m;
    float t;

    X = vecSub(ray.orig, topCapCenter1(cylin));
    a = dotProduct(ray.dir, ray.dir) - pow(dotProduct(ray.dir, cylin.axis), 2);
    c = dotProduct(X, X) - pow(dotProduct(X, cylin.axis), 2) - cylin.radius * cylin.radius;
    b = 2 * (dotProduct(ray.dir, X) - dotProduct(ray.dir, cylin.axis) * dotProduct(X, cylin.axis));
    t = solveQuadratic(a, b, c);
    if (t < 0)
        return (false);
    cross->t = t;
    point_calc(&cross->p, ray, t);
    m = dotProduct(ray.dir, cylin.axis) * cross->t + dotProduct(X, cylin.axis);
    if (m > cylin.height || m < 0)
        return (false);
    cross->n = cylinder_normal2(cylin, *cross, m);
    cross->color = cylin.tint;
    return (true);
}