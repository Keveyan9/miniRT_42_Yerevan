/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:07:50 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 00:07:53 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"minirt.h"

void	exit_code(int code, char *msg, t_scene *scene, char **string)
{
	write(2, msg, ft_strlen(msg));
	if (string)
		double_free(string);
	if (scene)
		free_scene(scene);
	exit(code);
}
