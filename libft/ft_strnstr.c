/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42madird.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:38:47 by alejogogi         #+#    #+#             */
/*   Updated: 2024/10/21 01:33:34 by alejagom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>/*borrar libreria*/

char	*ft_strnstr(const char *haystak, const char *needle, size_t n)
{
	size_t	i;
	size_t	a;

	if (!*needle)
	{
		return ((char *)haystak);
	}
	i = 0;
	while (i < n && haystak[i])
	{
		a = 0;
		while (haystak[i + a] == needle[a] && (i + a) < n)
		{
			if (needle[a + 1] == '\0')
			{
				return ((char *)&haystak[i]);
			}
			a++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	*texto;
	const char	*buscar;
	char		*res;
	size_t		i;

	texto = "Holla mundo";
	buscar = "mundo";
	i = 12;
	res = ft_strnstr(texto, buscar, i);
	if (res)
	{
		printf("sub string encontrado: '%s'\n", res);
	}
	else
	{
		printf("sub string no encontrado. \n");
	}
	return (0);
}
*/