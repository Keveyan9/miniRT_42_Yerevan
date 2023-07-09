/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:16:15 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 00:16:19 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

bool	intersectSphere(t_ray ray, t_sphere sphere, t_cross *cross)
{
	float	tOHdot;
	float	tHC;
	float	dSquare;
	float	t1;
	t_vec	L;

	L = vecSub(sphere.center, ray.orig);
	tOHdot = dotProduct(L, ray.dir);
	if (tOHdot < 0)
		return (false);
	dSquare = dotProduct(L, L) - tOHdot * tOHdot;
	if (dSquare > sphere.radius * sphere.radius)
		return (false);
	tHC = sqrt(sphere.radius * sphere.radius - dSquare);
	cross->t = tOHdot - tHC;
	t1 = tOHdot + tHC;
	if (cross->t > t1)
		swap(&cross->t, &t1);
	if (cross->t < 0)
	{
		cross->t = t1;
		if (cross->t < 0)
		return (false);
	}
	point_calc(&cross->p, ray, cross->t);
	cross->n = sphere_normal(cross->p, sphere.center);
	cross->color = sphere.tint;
	return (true);
}

bool	intersectPlane(t_ray ray, t_plane plane, t_cross *cross)
{
	float	denominator;

	denominator = dotProduct(plane.normal, ray.dir);
	if (denominator == 0)
		return (false);
	cross->t = (dotProduct(vecSub(plane.point, ray.orig), plane.normal))
		/ denominator;
	if (cross->t < EPSILON)
		return (false);
	cross->n = plane.normal;
	if (dotProduct(plane.normal, ray.dir) > 0)
		cross->n = vecInverse(cross->n);
	point_calc(&cross->p, ray, cross->t);
	cross->color = plane.tint;
	return (true);
}
