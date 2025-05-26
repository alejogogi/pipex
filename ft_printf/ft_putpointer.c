/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:04:13 by alejogogi         #+#    #+#             */
/*   Updated: 2025/01/08 21:34:13 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	unsigned long long	a;
	int					ln;

	ln = 0;
	a = (unsigned long long)ptr;
	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	ln += ft_putstr("0x");
	ln += ft_puthex(a, 'x');
	return (ln);
}
