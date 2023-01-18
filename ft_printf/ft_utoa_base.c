/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:53:33 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/14 18:05:45 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_uleng(unsigned int n, const char *base)
{
	size_t			index;
	unsigned int	n_cpy;
	size_t			base_leng;

	base_leng = ft_strlen(base);
	index = 0;
	if (n == 0)
		return (1);
	n_cpy = n;
	while (n_cpy > 0)
	{
		n_cpy /= base_leng;
		index++;
	}
	return (index);
}

void	ft_conv(char *dest, unsigned int n, const char *base)
{
	size_t			dest_leng;
	unsigned int	n_cpy;
	size_t			base_leng;

	base_leng = ft_strlen(base);
	dest_leng = ft_uleng(n, base);
	dest[dest_leng--] = '\0';
	if (!n)
		dest[dest_leng] = base[0];
	n_cpy = n;
	while (n_cpy)
	{
		dest[dest_leng--] = base[n_cpy % base_leng];
		n_cpy /= base_leng;
	}
}

char	*ft_utoa_base(unsigned int n, const char *base)
{
	char	*dest;

	if (!base)
		return (NULL);
	dest = (char *) ft_calloc((ft_uleng(n, base) + 1), (sizeof(char)));
	if (!dest)
		return (NULL);
	ft_conv(dest, n, base);
	return (dest);
}
