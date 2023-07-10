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

t_cross	*loop_sphere_list(t_sphere *sphere, t_ray ray, t_scene *scene)
{
	t_sphere	*head;
	t_cross		*cross;
	t_cross		tmp_cross;

	head = sphere;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmp_cross.t = INFINITY;
	while (head)
	{
		if (intersect_sphere(ray, *head, cross) && cross->t < tmp_cross.t)
			tmp_cross = *cross;
		head = head->next;
	}
	*cross = tmp_cross;
	return (cross);
}

t_cross	*loop_plane_list(t_plane *plane, t_ray ray, t_scene *scene)
{
	t_plane	*head;
	t_cross	*cross;
	t_cross	tmp_cross;

	head = plane;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmp_cross.t = INFINITY;
	while (head)
	{
		if (intersect_plane(ray, *head, cross) && cross->t < tmp_cross.t)
			tmp_cross = *cross;
		head = head->next;
	}
	*cross = tmp_cross;
	return (cross);
}

t_cross	*loop_cylin_list(t_cylinder *cylin, t_ray ray, t_scene *scene)
{
	t_cylinder	*head;
	t_cross		*cross;
	t_cross		tmp_cross;

	head = cylin;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmp_cross.t = INFINITY;
	while (head)
	{
		if (intersect_cylin(ray, *head, cross) && cross->t < tmp_cross.t)
			tmp_cross = *cross;
		head = head->next;
	}
	*cross = tmp_cross;
	return (cross);
}

bool	ray_trace(t_scene *scene, t_ray ray, t_cross **final_cross)
{
	float	t_near;
	t_cross	*cross_plane;
	t_cross	*cross_sphere;
	t_cross	*cross_cylin;

	t_near = INFINITY;
	cross_plane = loop_plane_list(scene->plane, ray, scene);
	cross_cylin = loop_cylin_list(scene->cylin, ray, scene);
	cross_sphere = loop_sphere_list(scene->sphere, ray, scene);
	t_near = find_min(cross_plane->t, cross_sphere->t, cross_cylin->t);
	if (t_near == cross_plane->t)
	{
		*final_cross = cross_plane;
		free_null(cross_sphere);
		free_null(cross_cylin);
	}
	else if (t_near == cross_sphere->t)
	{
		*final_cross = cross_sphere;
		free_null(cross_plane);
		free_null(cross_cylin);
	}
	else if (t_near == cross_cylin->t)
	{
		*final_cross = cross_cylin;
		free_null(cross_plane);
		free_null(cross_sphere);
	}
	if (t_near != INFINITY)
		return (1);
	return (0);
}

void	calculate(t_all *all, int x, int y)
{
	t_cross			*final_cross;
	t_ray			ray;
	t_color			col;
	unsigned int	color;

	final_cross = NULL;
	ray = ray_generate(x, y, *(all->scene->cam));
	ray_trace(all->scene, ray, &final_cross);
	if (final_cross->t == INFINITY)
		color = (0 << 16 | 0 << 8 | 0);
	else
	{
		col = final_lighting(all->scene, final_cross);
		color = make_int_from_rgb(col);
	}
	free_null(final_cross);
	my_mlx_pixel_put(all->mlx_data, x, y, color);
}
