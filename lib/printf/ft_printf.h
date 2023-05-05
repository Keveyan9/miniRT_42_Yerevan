/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:47:34 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/02 19:47:38 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *input, ...);
void	ft_print_char(int *len, int c);
void	ft_print_string(int *len, char *c);
void	ft_print_number(int *len, int number);
void	ft_print_unsigned( int *len, unsigned int num);
void	ft_print_hex(int *len, unsigned int hexcalcul, char *base);
void	ft_print_addres(int *len, unsigned long long int addres);
#endif
