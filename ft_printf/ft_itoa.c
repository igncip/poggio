/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:44:12 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/14 17:55:51 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrleng(int n)
{
	size_t			index;
	unsigned int	n_cpy;

	index = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n_cpy = n * -1;
		index++;
	}
	else
		n_cpy = n;
	while (n_cpy > 0)
	{
		n_cpy /= 10;
		index++;
	}
	return (index);
}

void	ft_conversion(char *dest, int n)
{
	size_t			dest_leng;
	unsigned int	n_cpy;

	dest_leng = ft_nbrleng(n);
	dest[dest_leng--] = '\0';
	if (!n)
		dest[dest_leng] = '0';
	if (n < 0)
	{
		dest[0] = '-';
		n_cpy = n * -1;
	}
	else
		n_cpy = n;
	while (n_cpy)
	{
		dest[dest_leng--] = n_cpy % 10 + '0';
		n_cpy /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*dest;

	dest = (char *) ft_calloc((ft_nbrleng(n) + 1), (sizeof(char)));
	if (!dest)
		return (NULL);
	ft_conversion(dest, n);
	return (dest);
}
