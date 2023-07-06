/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:54:27 by aivanyan          #+#    #+#             */
/*   Updated: 2023/06/21 23:42:21 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	sphere_normal(t_vec p, t_vec center)
{
	return (normalize(vecSub(p, center)));
}

void	topCapCenter(t_vec *top, t_cylinder cyl)
{
	top->x = cyl.center.x;
    top->y = cyl.center.y + cyl.height / 2;
    top->z = cyl.center.z;
}

void	bottomCapCenter(t_vec *bottom, t_cylinder cyl)
{
	bottom->x = cyl.center.x;
    bottom->y = cyl.center.y - cyl.height / 2;
    bottom->z = cyl.center.z;
}

t_vec	cylinder_normal(t_cylinder cyl, t_vec p)
{
	t_vec	bottom_center;
	t_vec	top_center;
	t_vec	v;
	t_vec	pt;
	float	t;

	bottomCapCenter(&bottom_center, cyl);
	topCapCenter(&top_center, cyl);

	if (distance(p, top_center) < cyl.radius)
		return (cyl.axis);
	if (distance(p, bottom_center) < cyl.radius)
		return (vecInverse(cyl.axis));
	else
	{
		v = vecSub(p, bottom_center);
		t = dotProduct(v, cyl.axis);
		pt = vecAdd(bottom_center, vecScale(t, cyl.axis));
		return (normalize(vecSub(p, pt)));
	}
}
