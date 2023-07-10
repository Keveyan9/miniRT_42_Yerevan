/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectCylin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:03 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:09:04 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	solve_quadratic(t_quadratic *q)
{
	q->delta = q->b * q->b - 4 * q->a * q->c;
	if (q->delta < 0)
		return (false);
	q->t1 = (-q->b - sqrt(q->delta)) / (q->a * 2);
	q->t2 = (-q->b + sqrt(q->delta)) / (q->a * 2);
	return (true);
}

bool	intersect_infinite_cylin(t_ray ray, t_cylinder cy, t_cross *cy_cross)
{
	t_quadratic	q;
	t_vec		u;
	t_vec		v;

	u = cross(ray.dir, cy.axis);
	v = vec_sub(ray.orig, cy.center);
	v = cross(v, cy.axis);
	q.a = dot_product(u, u);
	q.b = 2 * dot_product(u, v);
	q.c = dot_product(v, v) - cy.radius * cy.radius;
	if (!solve_quadratic(&q) || (q.t2 <= EPSILON && q.t1 <= EPSILON))
		return (false);
	if (q.t1 <= EPSILON || (q.t2 > EPSILON && (q.t2 < q.t1)))
		q.t1 = q.t2;
	cy_cross->t = q.t1;
	point_calc(&cy_cross->p, ray, q.t1);
	v = vec_sub(cy_cross->p, cy.center);
	cy_cross->n = cross(v, cy.axis);
	cy_cross->n = cross(cy_cross->n, cy.axis);
	cy_cross->n = normalize(cy_cross->n);
	if (dot_product(cy_cross->n, ray.dir))
		cy_cross->n = vec_inverse(cy_cross->n);
	return (true);
}

bool	intersect_cylin(t_ray ray, t_cylinder cylin, t_cross *cross)
{
	t_plane	pl;
	t_cross	c;

	cross->t = INFINITY;
	pl.point = cylin.top_cap_cent;
	pl.normal = cylin.axis;
	pl.tint = cylin.tint;
	if (intersect_plane(ray, pl, &c)
		&& distance(c.p, cylin.top_cap_cent) <= cylin.radius
		&& cross->t > c.t)
		*cross = c;
	pl.point = bottom_cap_center(cylin);
	if (intersect_plane(ray, pl, &c)
		&& distance(c.p, cylin.bottom_cap_cent) <= cylin.radius
		&& cross->t > c.t)
		*cross = c;
	if (intersect_infinite_cylin(ray, cylin, &c)
		&& pow(distance(cylin.center, c.p), 2)
		<= pow(cylin.height * 0.5, 2) + cylin.radius * cylin.radius
		&& cross->t > c.t)
		*cross = c;
	return (cross->t < INFINITY && cross->t > EPSILON);
}	
