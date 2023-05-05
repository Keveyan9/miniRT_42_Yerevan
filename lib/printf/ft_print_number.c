/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:46:39 by skeveyan          #+#    #+#             */
/*   Updated: 2022/07/30 12:47:15 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_number( int *len, int number)
{
	unsigned int	n;
	char			d;

	n = number;
	if (number < 0)
	{
		n = -number;
	(*len) += write(1, "-", 1);
	}
	if (n >= 10)
		ft_print_number(len, n / 10);
	d = n % 10 + '0';
	(*len) += write(1, &d, 1);
}
