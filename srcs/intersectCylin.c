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

// bool intersectCylin(t_ray ray, t_cylinder cylin, t_cross *cross)
// {
//     t_plane plane;
//     t_cross crossPlane;
//     float   t;

//     t = INFINITY;
//     plane.point = cylin.topCapCent;
//     plane.normal = vecInverse(cylin.axis);
//     if (intersectPlane(ray, plane, &crossPlane))
//     {
//         if (distance(crossPlane.p, cylin.topCapCent) <= cylin.radius && crossPlane.t < t )
//         {
//             *cross = crossPlane; 
//             t = cross->t;
//         }
//     }
//     plane.point = bottomCapCenter(cylin);
//     plane.normal = vecInverse(cylin.axis);
//     if (intersectPlane(ray, plane, &crossPlane))
//     {
//         if (distance(crossPlane.p, bottomCapCenter(cylin)) <= cylin.radius && crossPlane.t < t)
//         {
//             *cross = crossPlane;
//             t = cross->t;
//         }
//     }
//     if (intersectInfiniteCylin(ray, cylin, cross) && cross->t < t)
//         t = cross->t;
//     return (cross->t < INFINITY && cross->t > 1e-6);
// }

// bool solve_quadratic(t_quadratic *q)
// {
//     q->D = q->b * q->b - 4 * q->a * q->c;
//     if (q->D < 0)
//         return (false);
//     q->t1 = (-q->b - sqrt(q->D)) / (q->a * 2);
//     q->t2 = (-q->b + sqrt(q->D)) / (q->a * 2);
//     return (true);
// }

// bool intersectInfiniteCylin(t_ray ray, t_cylinder cylin, t_cross *cylinCross)
// {
//     t_quadratic q;
//     t_vec u;
//     t_vec v;

//     u = cross(ray.dir, cylin.axis);
//     v = vecSub(ray.orig, cylin.axis);
//     v = cross(v, cylin.axis);
//     q.a = dotProduct(u, u);
//     q.b = 2 * dotProduct(u, v);
//     q.c = dotProduct(v, v) - cylin.radius * cylin.radius;
//     if (!solve_quadratic(&q) || (q.t2 <= EPSILON && q.t1 <= EPSILON))
//         return (false);
//     if (q.t1 <= EPSILON || (q.t2 > EPSILON && (q.t2 < q.t1)))
//         q.t1 = q.t2;
//     cylinCross->t = q.t1;
//     point_calc(&cylinCross->p, ray, q.t1);
//     v = vecSub(cylinCross->p, cylin.center);
//     cylinCross->n = cross(v, cylin.axis);
//     cylinCross->n = cross(cylinCross->n, cylin.axis);
//     cylinCross->n = normalize(cylinCross->n);
//     if (dotProduct(cylinCross->n, ray.dir))
//         cylinCross->n = vecInverse(cylinCross->n);
//     return (true);
// }

bool intersectCylin(t_ray ray, t_cylinder cylin, t_cross *cross)
{
    t_plane pl;
    t_cross c;

    cross->t = INFINITY;
    pl.point = cylin.topCapCent;
    pl.normal = cylin.axis;
    if (intersectPlane(ray, pl, &c)
        && distance(c.p, cylin.topCapCent) <= cylin.radius
        && cross->t > c.t)
        *cross = c;
    pl.point = bottomCapCenter(cylin);
    if (intersectPlane(ray, pl, &c)
        && distance(c.p, cylin.topCapCent) <= cylin.radius
        && cross->t > c.t)
        *cross = c;
    if (intersectInfiniteCylin(ray, cylin, &c)
        && pow(distance(cylin.center, c.p), 2)
        <= pow(cylin.height * 0.5, 2) + cylin.radius * cylin.radius
        && cross->t > c.t)
        *cross = c;
    return (cross->t < INFINITY && cross->t > EPSILON);
}