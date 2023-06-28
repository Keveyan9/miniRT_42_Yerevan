/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:39:09 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/12 18:11:10 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:39:09 by skeveyan          #+#    #+#             */
/*   Updated: 2023/06/08 01:21:05 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
<<<<<<< HEAD
#  define BUFFER_SIZE 42
=======
#  define BUFFER_SIZE 1
>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
<<<<<<< HEAD
=======
# include <stdint.h>
# include "../libft/libft.h"

>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	chekin_n(char *s);
int		write_return(char **temporary, char **returnline, size_t *i_return);
char	*ft_strjoin(char const *s1, char const *s2);
int		read_chek(int fd, char **temporary, long int *read_value);
int		take_temporary(char **temporary, size_t *i_return);
void	freek(char **s);
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba
