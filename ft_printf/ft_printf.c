/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:55:17 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/18 18:40:42 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent(format);
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	va_list	args;
	int		print_length;

	index = 0;
	print_length = 0;
	va_start(args, str);
	while (str[index] != '\n')
	{
		if (str[index] == '%')
		{
			print_length += ft_formats(args, str[index + 1]);
			index ++;
		}
		else
			print_length += ft_printchar(str[index]);
		index++;
	}
	va_end(args);
	return (print_length);
}
