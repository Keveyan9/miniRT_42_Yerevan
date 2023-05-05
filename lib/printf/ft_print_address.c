/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:37:32 by skeveyan          #+#    #+#             */
/*   Updated: 2022/07/25 19:37:33 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

void	ft_print_addres(int *len, unsigned long long int addres)
{
	char	*hexform_lowercase;

	hexform_lowercase = "0123456789abcdef";
	if (addres >= 16)
		ft_print_addres(len, addres / 16);
	write(1, &hexform_lowercase[addres % 16], 1);
	(*len)++;
}
