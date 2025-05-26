/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:04:48 by alejogogi         #+#    #+#             */
/*   Updated: 2025/01/09 18:53:18 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long num, char c)
{
	char	*hex;
	int		ln;

	ln = 0;
	if (c == 'X')
	{
		hex = "0123456789ABCDEF";
	}
	else if (c == 'x')
	{
		hex = "0123456789abcdef";
	}
	else
		return (0);
	if (num >= 16)
	{
		ln = ln + ft_puthex(num / 16, c);
	}
	ln += ft_putchar(hex[num % 16]);
	return (ln);
}
