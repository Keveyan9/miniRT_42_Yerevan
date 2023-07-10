/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:54:27 by aivanyan          #+#    #+#             */
/*   Updated: 2023/07/10 11:43:44 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	sphere_normal(t_vec p, t_vec center)
{
	return (normalize(vecSub(p, center)));
}

t_vec topCapCenter(t_cylinder cyl)
{
    t_vec top;

    top = vecScale(-0.5 * cyl.height, cyl.axis);
    top = vecAdd(cyl.center, top);
    return (top);
}

t_vec bottomCapCenter(t_cylinder cyl)
{
    t_vec btm;

    btm = vecScale(0.5 * cyl.height, cyl.axis);
    btm = vecAdd(btm, cyl.center);
    return (btm);
}

t_vec	cylinder_normal(t_cylinder cyl, t_vec p)
{
	t_vec	bottom_center;
	t_vec	top_center;
	t_vec	v;
	t_vec	pt;
	float	t;

	bottom_center = bottomCapCenter(cyl);
	top_center = topCapCenter(cyl);
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