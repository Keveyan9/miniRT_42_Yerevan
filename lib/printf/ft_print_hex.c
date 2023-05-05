/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:41:43 by skeveyan          #+#    #+#             */
/*   Updated: 2022/12/16 15:33:56 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_hex(int *len, unsigned int hexcalcul, char *base)
{
	if (hexcalcul >= 16)
		ft_print_hex(len, hexcalcul / 16, base);
	write(1, &base[hexcalcul % 16], 1);
	(*len)++;
}
