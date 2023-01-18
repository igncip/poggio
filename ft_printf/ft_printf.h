/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:54:59 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/18 18:32:46 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(uintptr_t ptr);
int		ft_printnbr(int number);
int		ft_print_unsigned(unsigned int unsign_nbr);
int		ft_print_hex(unsigned int hex_nbr, const char format);
int		ft_printpercent(const char format);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_free(char **str);
char	*ft_itoa(int n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_ptrtoa(uintptr_t ptr);
size_t	ft_strlen(const char *s);
char	*ft_utoa_base(unsigned int n, const char *base);

#endif