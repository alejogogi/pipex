/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:53:46 by alejogogi         #+#    #+#             */
/*   Updated: 2025/04/09 20:46:18 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **result, int i_word)
{
	while (i_word > 0)
		free(result[--i_word]);
	free(result);
}

static int	ft_contador(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			cont++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (cont);
}

static char	**new_words(char **result, char const *s, char c)
{
	int	i;
	int	start;
	int	i_word;

	i = 0;
	i_word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			result[i_word] = ft_substr(s, start, i - start);
			if (result[i_word] == NULL)
				return (NULL);
			i_word++;
		}
	}
	result[i_word] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		c_words;

	c_words = ft_contador(s, c);
	result = (char **)ft_calloc((c_words + 1), sizeof(char *));
	if (!result)
		return (NULL);
	if (new_words(result, s, c) == NULL)
	{
		free_memory(result, c_words);
		return (NULL);
	}
	return (result);
}

/*
int	main(void)
{
	const char	*str = "hola,mundo,esto,es,una,prueba";
	char		delimiter;
	char		**resultado;
	int			i;

	delimiter = ',';
	resultado = ft_split(str, delimiter);
	if (!resultado)
	{
		printf("Error al dividir la cadena\n");
		return (1);
	}
	i = 0;
	while (resultado[i] != NULL)
	{
		printf("Subcadena %d: %s\n", i, resultado[i]);
		i++;
	}
	i = 0;
	while (resultado[i] != NULL)
	{
		free(resultado[i]);
		i++;
	}
	free(resultado);
	return (0);
}
*/