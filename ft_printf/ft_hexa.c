/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:30:52 by riel-fas          #+#    #+#             */
/*   Updated: 2024/12/09 10:45:49 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long nb, char c)
{
	char	*base;
	char	str[17];
	int		i;
	int		counter;

	base = "0123456789abcdef";
	counter = 0;
	i = 0;
	if (c == 'p')
		counter += ft_str("0x");
	if (nb == 0)
		counter += ft_char('0');
	if (c == 'X')
		base = "0123456789ABCDEF";
	while (nb)
	{
		str[i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	str[i--] = '\0';
	while (i >= 0)
		counter += ft_char(str[i--]);
	return (counter);
}
