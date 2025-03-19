/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:29:11 by riel-fas          #+#    #+#             */
/*   Updated: 2024/12/09 10:47:22 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char m, va_list p)
{
	int	q;

	q = 0;
	if (m == 'c')
		q += ft_char(va_arg(p, int));
	else if (m == 's')
		q += ft_str(va_arg(p, char *));
	else if (m == 'd' || m == 'i')
		q += ft_nbr(va_arg(p, int));
	else if (m == 'u')
		q += ft_unbr(va_arg(p, unsigned int));
	else if (m == 'p')
		q += ft_hexa(va_arg(p, unsigned long), m);
	else if (m == 'x')
		q += ft_hexa(va_arg(p, unsigned int), m);
	else if (m == 'X')
		q += ft_hexa(va_arg(p, unsigned int), m);
	else if (m == '%')
		q += ft_char('%');
	else
		q += ft_char(m);
	return (q);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	va_start(p, str);
	while (str[x])
	{
		if (str[x] == '%')
		{
			if (!str[x + 1])
				return (y);
			y += ft_check(str[x + 1], p);
			x++;
		}
		else
		{
			y += ft_char(str[x]);
		}
		x++;
	}
	va_end(p);
	return (y);
}
