/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:21:26 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/21 09:59:37 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>


int	ft_printf(const char *str, ...);
int	ft_char(char c);
int	ft_str(char *str);
int	ft_hexa(unsigned long nbr, char c);
int	ft_nbr(int i);
int	ft_unbr(unsigned int nbr);

#endif
