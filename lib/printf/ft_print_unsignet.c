/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:14:21 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/01 19:14:51 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_unsigned( int *len, unsigned int num)
{
	char	d;

	if (num >= 10)
		ft_print_unsigned(len, num / 10);
	d = num % 10 + '0';
	(*len) += write(1, &d, 1);
}
