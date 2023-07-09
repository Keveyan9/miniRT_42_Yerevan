/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:30:02 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 00:30:05 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec	vecMultMatrix(t_matrix m, t_vec v)
{
	t_vec	dest;

	dest.x = v.x * m.right.x + v.y * m.up.x + v.z * m.forward.x;
	dest.y = v.x * m.right.y + v.y * m.up.y + v.z * m.forward.y;
	dest.z = v.x * m.right.z + v.y * m.up.z + v.z * m.forward.z;
	return (dest);
}

t_vec	rayDirGenerate(t_matrix lookAt, t_cam camera, float x, float y)
{
	t_vec	rayDir;
	float	scale;
	float	aspectRatio;

	if (HEIGHT < WIDTH)
		aspectRatio = (float)WIDTH / (float)HEIGHT;
	else
		aspectRatio = (float)HEIGHT / (float)WIDTH;
	scale = tan((camera.fov * 0.5 * M_PI) / 180);
	rayDir.x = (2.0 * (x + 0.5) / (float)WIDTH - 1.0) * scale * aspectRatio;
	rayDir.y = (1.0 - 2.0 * (y + 0.5) / (float)HEIGHT) * scale;
	rayDir = vecMultMatrix(lookAt, rayDir);
	rayDir = normalize(rayDir);
	return (rayDir);
}

t_ray	rayGenerate(float x, float y, t_cam camera)
{
	t_ray		ray;
	t_matrix	lookAt;

	ray.orig = camera.orig;
	LookAt(&lookAt, camera);
	ray.dir = rayDirGenerate(lookAt, camera, x, y);
	return (ray);
}
