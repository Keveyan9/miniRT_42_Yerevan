/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isIntSet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:19:20 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 00:19:24 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "scene.h"

int	isInSet(char c)
{
	int	j;

	j = -1;
	while (SPLIT_SET[++j])
	{
		if (c == SPLIT_SET[j])
			return (1);
	}
	return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\f'
		|| c == '\n' || c == '\r' || c == '\v');
}
