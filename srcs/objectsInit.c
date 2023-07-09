/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectsInit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:26:43 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 00:26:46 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	initVector(t_vec vector, t_vec *objVect)
{
	(*objVect).x = vector.x;
	(*objVect).y = vector.y;
	(*objVect).z = vector.z;
}

void	initColor(t_color tint, t_color *ambTint)
{
	(*ambTint).r = tint.r / 255;
	(*ambTint).g = tint.g / 255;
	(*ambTint).b = tint.b / 255;
}

t_ambient	*initAmbient(float ratio, t_color tint,t_scene *scene)
{
	t_ambient	*amb;

	amb = malloc(sizeof(t_ambient));
	if (!amb)
		exit_code(1, "ambient malloc failed", scene, NULL);
	initColor(tint, &(amb->tint));
	amb->ratio = ratio;
	return (amb);
}

t_cam	*initCam(t_vec origin, t_vec orient, float fov, t_scene *scene)
{
	t_cam	*camera;

	camera = malloc(sizeof(t_cam));
	if (!camera)
		exit_code(1, "camera malloc failed", scene, NULL);
	initVector(origin, &(camera->orig));
	initVector(orient, &(camera->orientation));
	camera->fov = fov;
	return (camera);
}

t_light	*initLight(t_vec orig, float ratio, t_color tint, t_scene *scene)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		exit_code(1, "origin malloc failed", scene, NULL);
	initVector(orig, &(light->orig));
	initColor(tint, &(light->tint));
	light->ratio = ratio;
	return (light);
}
