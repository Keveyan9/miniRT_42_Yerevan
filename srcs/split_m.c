/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:31:44 by aivanyan          #+#    #+#             */
/*   Updated: 2023/06/03 03:14:38 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/zkarapet/Desktop/newminirt/includes/minirt.h"

static int	ft_count(char const *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (!isInSet(*s) && (isInSet(*(s + 1)) || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char const	*ft_start(char const *s)
{
	while (*s)
	{
		if (!isInSet(*s))
			return (s);
		s++;
	}
	return (NULL);
}

static char const	*ft_end(char const *s)
{
	while (*s)
	{
		if (!isInSet(*s) && (isInSet(*(s + 1)) || (*(s + 1) == '\0')))
			return (s);
		s++;
	}
	return (NULL);
}

static int	ft_check_alloc(char **split, char *str, int index)
{
	if (str)
		return (0);
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (1);
}

char	**ft_split_m(char const *s)
{
	char	**split;
	int		count;
	int		i;
	int		end;

	count = ft_count(s);
	split = ft_calloc((count + 1), sizeof(s));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		s = ft_start(s);
		end = ft_end(s) - s + 1;
		split[i] = malloc((end + 1) * sizeof(char));
		if (ft_check_alloc(split, split[i], i))
			return (NULL);
		ft_strlcpy(split[i++], s, end + 1);
		s += end;
	}
	return (split);
}