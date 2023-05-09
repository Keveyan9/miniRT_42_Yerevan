/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:09:35 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/16 17:09:48 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	chekin_n(char *s);
int		write_return(char **temporary, char **returnline, size_t *i_return);
char	*ft_strjoin(char const *s1, char const *s2);
int		read_chek(int fd, char **temporary, long int *read_value);
int		take_temporary(char **temporary, size_t *i_return);
void	freek(char **s);
#endif
