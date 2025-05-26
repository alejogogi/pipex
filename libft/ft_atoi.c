/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:54:19 by alejagom          #+#    #+#             */
/*   Updated: 2025/04/12 11:04:27 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

long	ft_atoi(const char *str)
{
	long	res;
	long	sig;

	res = 0;
	sig = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sig);
}

/*
int	main(void)
{
	char	str[20];
	int		num;

	printf("Escribe un número en texto: ");
	scanf("%s", str);
	num = ft_atoi(str);
	printf("El número es: %d\n", num);
	return (0);
} */
