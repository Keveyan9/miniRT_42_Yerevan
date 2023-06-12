/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:20:59 by aivanyan          #+#    #+#             */
/*   Updated: 2023/06/12 02:51:07 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec   vecAdd(t_vec a, t_vec b)
{
	t_vec	p;

	p.x = a.x + b.x;
	p.y = a.y + b.y;
	p.z = a.z + b.z;
	return (p);
}

t_vec   vecSub(t_vec a, t_vec b)
{
	t_vec	p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.z = a.z - b.z;
	return (p);
}

float   dotProduct(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec   cross(t_vec a, t_vec b)
{
	t_vec	cp;

	cp.x = a.y * b.z - a.z * b.y;
	cp.y = a.z * b.x - a.x * b.z;
	cp.z = a.x * b.y - a.y * b.x;
	return (cp);
}

t_vec   normalize(t_vec p)
{
	t_vec	n;
	float	len;

	len = sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
	n.x = p.x / len;
	n.y = p.y / len;
	n.z = p.z / len;
	return (n);
}

t_vec   vecScale(float n, t_vec p)
{
	t_vec   v;

	v.x = n * p.x;
	v.y = n * p.y;
	v.z = n * p.z;
	return (v);
}

float   distance(t_vec p1, t_vec p2)
{
	return (sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2) + powf(p2.z - p1.z, 2)));
}