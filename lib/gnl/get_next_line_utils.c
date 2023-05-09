/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:53 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/12 17:52:48 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

size_t	chekin_n(char *s)
{
	size_t	n;

	n = 0;
	if (s)
	{
		while (s[n] && s[n] != '\n')
		n++;
		if (s[n] == '\n')
			return (0);
	}
	return (1);
}

void	freek(char **s)
{
	if (*s)
	{
		free(*s);
		(*s) = NULL;
	}
}