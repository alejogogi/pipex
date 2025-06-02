/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:01:00 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/02 21:32:15 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_comands(t_node *head)
{
	t_node	*temp;
	int		i;

	temp = head;
	while (temp) // Recorrer cada nodo de la lista
	{
		i = 0;
		while (temp->agrs[i] != NULL)
		{
			ft_printf("%s\n", temp->agrs[i]);
				// imprime los argumentos del nodo, y es null porque es char **
			i++;
		}
		temp = temp->next;
	}
}

int	main(int ln, char **args, char **envt)
{
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (ln < 5)
		return (ft_printf("Error\n"));
	check_file(ln, args, &(*tools));
	tools->commands = NULL;
	parc_command(ln, args, tools);
	print_comands(tools->commands);
	ft_printf("cantidad de comandos %d\n", tools->size);
	free_tools(tools);
}
