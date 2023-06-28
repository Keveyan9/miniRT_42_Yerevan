/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:53 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/12 17:52:48 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	if (s)
	{
		while (s[n])
		n++;
	}
	return (n);
}

char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*str;

	n = 0;
	if (s)
	{
		str = malloc(ft_strlen(s) * sizeof(char) + 1);
		if (!str)
			return (NULL);
		while (*s)
			str[n++] = *s++;
		str[n] = '\0';
		return (str);
	}
	return (NULL);
}
=======
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:53 by skeveyan          #+#    #+#             */
/*   Updated: 2023/06/03 03:07:52 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba

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

<<<<<<< HEAD
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nowstring;
	size_t	n;
	size_t	t;

	n = 0;
	t = 0;
	if (!s2)
		return (NULL);
	nowstring = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nowstring)
		return (0);
	while (s1 && s1[n])
	{	
		nowstring[n] = s1[n];
		n++;
	}
	while (s2 && s2[t])
		nowstring[n++] = s2[t++];
	nowstring [n] = '\0';
	return (nowstring);
}

=======
>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba
void	freek(char **s)
{
	if (*s)
	{
		free(*s);
		(*s) = NULL;
	}
}
