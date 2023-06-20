/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:51:31 by aivanyan          #+#    #+#             */
/*   Updated: 2023/06/21 01:48:59 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ambient_lighting(t_ambient *ambient)
{
	return (colorMul(ambient->tint, ambient->ratio));
}

t_color	diffuse_lighting(t_light *light, t_cross *cross)
{
	t_vec	light_ray;
	float	dot;
	
	light_ray = normalize(vecSub(light->orig, cross->p));
	dot	= dotProduct(light_ray, cross->n);
	if (dot < 0)
		dot = 0;
	return (colorMul(light->tint, light->ratio * dot));
}

//strenght between 0-1, shininess prefered 32 can add in light
t_color	specular_lightning(t_light *light, t_cross *cross, t_cam  *cam, float strength, float s)
{
	t_vec	light_ray;
	t_vec	reflect_ray;
	t_vec	view_ray;
	float	dot;
	
	light_ray = normalize(vecSub(light->orig, cross->p));
	reflect_ray = reflect_vec(light_ray, cross->n);
	view_ray = normalize(vecSub(cam->orig, cross->p));
	dot	= dotProduct(view_ray, reflect_ray);
	if (dot < 0)
		dot = 0;
	dot = pow(dot, s);
	return (colorMul(light->tint, dot * strength));
}

bool	shadow(t_cross *cross, t_light *light)
{
	t_ray	shadow_ray;

	shadow_ray.orig = cross->p;
	shadow_ray.dir = normalize(vecSub(light->orig, cross->p));
	point_calc(&shadow_ray.orig, shadow_ray, 1e-4);
	//if intersect an object &&  (distance(cross->p, light->orig) > distance(cross->p, shadow's croos_point))
	return (true);
}