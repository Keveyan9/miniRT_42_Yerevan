/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:39:29 by aivanyan          #+#    #+#             */
/*   Updated: 2023/07/02 16:16:15 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	colorMul(t_color c, float f)
{
	t_color	col;

	col.r = c.r * f;
	col.g = c.g * f;
	col.b = c.b * f;
	return (col);
}

t_color	init_color(float r, float g, float b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_vec	reflect_vec(t_vec l, t_vec n)
{
	t_vec	r;

	r = vecMul(n, 2 * dotProduct(n, l));
	r = vecSub(l, r);
	return (r);
}

void	point_calc(t_vec *p, t_ray r, float t)
{
	p->x = r.orig.x + t * r.dir.x;
	p->y = r.orig.y + t * r.dir.y;
	p->z = r.orig.z + t * r.dir.z;
}

t_color	final_color(t_cross *cross, t_color amb, t_color diff, t_color spec)
{
	t_color	col;


	col.r = amb.r + diff.r + spec.r;
	col.g = amb.g + diff.g + spec.g;
	col.b = amb.b + diff.b + spec.b;
	if (col.r > 1)
		col.r = 1;
	if (col.g > 1)
		col.g = 1;
	if (col.b > 1)
		col.b = 1;
	col.r *= cross->color.r;
	col.g *= cross->color.g;
	col.b *= cross->color.b;
	return (col);
}