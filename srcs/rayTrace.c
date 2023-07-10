/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayTrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:30:11 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 00:30:13 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_cross	*loopSphereList(t_sphere *sphere, t_ray ray, t_scene *scene)
{
	t_sphere	*head;
	t_cross		*cross;
	t_cross		tmpCross;

	head = sphere;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmpCross.t = INFINITY;
	while (head)
	{
		if (intersectSphere(ray, *head, cross) && cross->t < tmpCross.t)
			tmpCross = *cross;
		head = head->next;
	}
	*cross = tmpCross;
	return (cross);
}

t_cross	*loopPlaneList(t_plane *plane, t_ray ray, t_scene *scene)
{
	t_plane	*head;
	t_cross	*cross;
	t_cross	tmpCross;

	head = plane;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmpCross.t = INFINITY;
	while (head)
	{
		if (intersectPlane(ray, *head, cross) && cross->t < tmpCross.t)
			tmpCross = *cross;
		head = head->next;
	}
	*cross = tmpCross;
	return (cross);
}

t_cross	*loopCylinList(t_cylinder *cylin, t_ray ray, t_scene *scene)
{
	t_cylinder	*head;
	t_cross		*cross;
	t_cross		tmpCross;

	head = cylin;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmpCross.t = INFINITY;
	while (head)
	{
		if (intersectCylin(ray, *head, cross) && cross->t < tmpCross.t)
			tmpCross = *cross;
		head = head->next;
	}
	*cross = tmpCross;
	return (cross);
}

bool	rayTrace(t_scene *scene, t_ray ray, t_cross **finalCross)
{
	float	tNear;
	t_cross	*crossPlane;
	t_cross	*crossSphere;
	t_cross	*crossCylin;

	tNear = INFINITY;
	crossPlane = loopPlaneList(scene->plane, ray, scene);
	crossCylin = loopCylinList(scene->cylin, ray, scene);
	crossSphere = loopSphereList(scene->sphere, ray, scene);
	tNear = findMin(crossPlane->t, crossSphere->t, crossCylin->t);
	if (tNear == crossPlane->t)
	{
		*finalCross = crossPlane;
		free_null(crossSphere);
		free_null(crossCylin);
	}
	else if (tNear == crossSphere->t)
	{
		*finalCross = crossSphere;
		free_null(crossPlane);
		free_null(crossCylin);
	}
	else if (tNear == crossCylin->t)
	{
		*finalCross = crossCylin;
		free_null(crossPlane);
		free_null(crossSphere);
	}
	if (tNear != INFINITY)
		return (1);
	return (0);
}

// int	create_rgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }

void	calculate(t_all *all , int x, int y)
{
	t_cross			*finalCross;
	t_ray			ray;
	t_color			col;
	unsigned int	color;

	finalCross = NULL;
	ray = rayGenerate(x, y, *(all->scene->cam));
	rayTrace(all->scene, ray, &finalCross);
	if (finalCross->t == INFINITY)
		color = (0 << 16 | 0 << 8 | 0);
	else
	{
		col = final_lighting(all->scene, finalCross);
		color = makeIntFromRGB(col);
	}
	free_null(finalCross);
	my_mlx_pixel_put(all->mlxData, x, y, color);
}
