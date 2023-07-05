/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:51:31 by aivanyan          #+#    #+#             */
/*   Updated: 2023/07/02 16:37:55 by aivanyan         ###   ########.fr       */
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
	t_color	color;

	light_ray = normalize(vecSub(light->orig, cross->p));
	dot = dotProduct(light_ray, cross->n);
	if (dot < 0)
		dot = 0;
	color = colorMul(light->tint, light->ratio * dot);
	return (color);
}

t_color	specular_lightning(t_scene *scene, t_cross *cross)
{
	t_vec	light_ray;
	t_vec	reflect_ray;
	t_vec	view_ray;
	float	dot;
	t_color	col;

	light_ray = normalize(vecSub(cross->p, scene->light->orig));
	reflect_ray = reflect_vec(light_ray, cross->n);
	view_ray = normalize(vecSub(scene->cam->orig, cross->p));
	dot = dotProduct(view_ray, reflect_ray);
	if (dot < 0)
		dot = 0;
	dot = pow(dot, SHININESS);
	col = colorMul(scene->light->tint, dot * STRENGTH);
	return (col);
}

bool	shadow(t_cross *cross, t_scene *scene)
{
	t_ray	shadow_ray;
	t_cross	*sdw_cross;


	shadow_ray.orig = cross->p;
	shadow_ray.dir = normalize(vecSub(scene->light->orig, cross->p));
	point_calc(&shadow_ray.orig, shadow_ray, 1e-4);
	if (rayTrace(scene, shadow_ray, &sdw_cross) && \
		(distance(cross->p, scene->light->orig)
			> distance(cross->p, sdw_cross->p)))
	{
		free_null(sdw_cross);
		return (true);
	}
	free_null(sdw_cross);
	return (false);
}

t_color	final_lighting(t_scene *scene, t_cross *cross)
{
	t_color	amb_factor;
	t_color	diffuse;
	t_color	specular;

	if (!shadow(cross, scene))
	{
		amb_factor = ambient_lighting(scene->amb);
		diffuse = diffuse_lighting(scene->light, cross);
		specular = specular_lightning(scene, cross);
		cross->color = final_color(cross, amb_factor, diffuse, specular);
	}
	else
		cross->color = init_color(0, 0, 0);
	return (cross->color);
}
