#include "minirt.h"

bool	intersect_infinite_cylin(t_ray ray, t_cylinder cy, t_cross *cy_cross)
{
	t_quadratic	q;
	t_vec		u;
	t_vec		v;

	u = cross(ray.dir, cy.axis);
    v = vecSub(ray.orig, cy.center);
    v = cross(v, cy.axis);
    q.a = dotProduct(u, u);
    q.b = 2 * dotProduct(u, v);
    q.c = dotProduct(v, v) - cy.radius * cy.radius;
    if (!solve_quadratic(&q) || (q.t2 <= EPSILON && q.t1 <= EPSILON))
    	return (false);
    if (q.t1 <= EPSILON || (q.t2 > EPSILON && (q.t2 < q.t1)))
    	q.t1 = q.t2;
    cy_cross->t = q.t1;
    point_calc(&cy_cross->p, ray, q.t1);
    v = vecSub(cy_cross->p, cy.center);
    cy_cross->n = cross(v, cy.axis);
    cy_cross->n = cross(cy_cross->n, cy.axis);
    cy_cross->n = normalize(cy_cross->n);
    if (dotProduct(cy_cross->n, ray.dir))
    	cy_cross->n = vecInverse(cy_cross->n);
    return (true);
}

bool	intersect_cylin(t_ray ray, t_cylinder cylin, t_cross *cross)
{
    t_plane	pl;
    t_cross	c;

    cross->t = INFINITY;
    pl.point = cylin.topCapCent;
    pl.normal = cylin.axis;
    pl.tint = cylin.tint;
    if (intersectPlane(ray, pl, &c)
        && distance(c.p, cylin.topCapCent) <= cylin.radius
        && cross->t > c.t)
        *cross = c;
    pl.point = bottomCapCenter(cylin);
    if (intersectPlane(ray, pl, &c)
        && distance(c.p, cylin.bottomCapCent) <= cylin.radius
        && cross->t > c.t)
        *cross = c;
    if (intersect_infinite_cylin(ray, cylin, &c)
        && pow(distance(cylin.center, c.p), 2)
        <= pow(cylin.height * 0.5, 2) + cylin.radius * cylin.radius
        && cross->t > c.t)
        *cross = c;
    return (cross->t < INFINITY && cross->t > EPSILON);
}
