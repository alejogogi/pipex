/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:44:09 by alejogogi         #+#    #+#             */
/*   Updated: 2025/01/10 20:41:55 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (!s)
		s = "(null)";
	while (s[c])
	{
		ft_putchar(s[c]);
		c++;
	}
	return (c);
}

// int	main(void)
// {
// 	char	*c = NULL;
// 	int	b;

// 	b = ft_putstr(c);
// 	write (1, "\n", 1);
// 	printf("long: %d\n", b);
// 	return (0);
// }
