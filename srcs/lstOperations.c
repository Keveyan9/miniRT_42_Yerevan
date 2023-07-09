/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstOperations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:22:54 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 00:22:58 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	init_scene(t_scene *scene)
{
	scene->amb = NULL;
	scene->cam = NULL;
	scene->light = NULL;
	scene->sphere = NULL;
	scene->begin_sphere = NULL;
	scene->plane = NULL;
	scene->begin_plane = NULL;
	scene->cylin = NULL;
	scene->begin_cylinder = NULL;
}
