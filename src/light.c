/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:51:31 by aivanyan          #+#    #+#             */
/*   Updated: 2023/06/08 03:31:55 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ambient_lightning(t_ambient *amb, float ambient[3])
{
	int		i;

	i = -1;
	while (++i < 3)
		ambient[i] = amb->tint[i] * amb->ratio;
}

float	diffuse_lightning(float	crossing_point[3], float normal[3], t_light *light)
{
	float	light_ray[3];
	float	dot;
	
	vec_subtract(light_ray, light->orig, crossing_point);
	normalize(light_ray);
	dot = dot_product(light_ray, normal);
	if (dot < 0)
		dot = 0;
	return (dot * light->ratio);
}

// ambient from ambient_lightning function and diffuse from diffuse_lightning
void	final_color(float ambient[3], float diffuse, float tint[3]) // pass tint of an intersected object
{
	int	i;

	i = -1;
	while (++i < 3)
		tint[i] = (ambient[i] + diffuse) * tint[i];
}


//using in diffuse lightning if sphere
void	sphere_normal(float normal[3], float crossing_point[3], float center[3])
{
	vec_subtract(normal, crossing_point, center);
	normalize(normal);
}