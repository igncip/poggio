/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_elaboration.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:54:21 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/14 18:10:01 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(uintptr_t ptr)
{
	char	*dest;
	int		print_length;

	dest = ft_ptrtoa(ptr);
	print_length = ft_printstr(dest);
	ft_free(&dest);
	return (print_length);
}

int	ft_printnbr(int number)
{
	char	*dest;
	int		print_length;

	dest = ft_itoa(number);
	print_length = ft_printstr(dest);
	ft_free(&dest);
	return (print_length);
}

int	ft_print_unsigned(unsigned int unsign_nbr)
{
	char	*dest;
	int		print_length;

	dest = ft_utoa_base(unsign_nbr, "0123456789");
	print_length = ft_printstr(dest);
	ft_free(&dest);
	return (print_length);
}

int	ft_print_hex(unsigned int hex_nbr, const char format)
{
	char	*dest;
	int		print_length;

	if (format == 'x')
		dest = ft_utoa_base(hex_nbr, "0123456789abcdef");
	else
		dest = ft_utoa_base(hex_nbr, "0123456789ABCDEF");
	print_length = ft_printstr(dest);
	ft_free(&dest);
	return (print_length);
}

int	ft_printpercent(const char format)
{
	if (format == '%')
		write(1, "%", 1);
	else
		write(1, "%", 1);
	return (1);
}
