/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:15:36 by skeveyan          #+#    #+#             */
/*   Updated: 2022/05/27 23:15:38 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	printing_convert(int *len, const char *input, va_list *argument)
{
	if (*input == 'c')
		ft_print_char(len, (va_arg(*argument, int )));
	else if (*input == 's')
		ft_print_string(len, (va_arg(*argument, char *)));
	else if (*input == 'p')
	{
		(*len) += write(1, "0x", 2);
		ft_print_addres(len, (va_arg(*argument, unsigned long long int)));
	}
	else if (*input == 'd' || *input == 'i')
		ft_print_number(len, (va_arg(*argument, int)));
	else if (*input == 'u')
		ft_print_unsigned(len, (va_arg(*argument, unsigned int)));
	else if (*input == 'x')
		ft_print_hex(len, (va_arg(*argument, unsigned int)),
			"0123456789abcdef");
	else if (*input == 'X')
		ft_print_hex(len, (va_arg(*argument, unsigned int)),
			"0123456789ABCDEF");
	else if (*input == '%')
		(*len) += write(1, "%", 1);
}

int	ft_printf(const char *input, ...)
{
	va_list	argument;
	int		len;

	len = 0;
	va_start(argument, input);
	while (*input)
	{
		if (*input == '%')
		{
			while (*input == ' ')
				input++;
			if (*input)
				input++;
			printing_convert(&len, input, &argument);
		}
		else if (*(input))
				len += write(1, input, 1);
		input++;
	}
	va_end(argument);
	return (len);
}
