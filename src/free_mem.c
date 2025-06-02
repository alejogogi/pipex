/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:29:50 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/02 19:18:13 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(t_node *head)
{
	t_node	*temp;
	int		i;

	while (head)
	{
		temp = head;
		i = 0;
		if (temp)
		{
			while (temp->agrs[i] != NULL)
			{
				free(temp->agrs[i]);
				i++;
			}
			free(temp->agrs);
		}
		head = head->next;
		free(temp);
	}
}

void	free_tools(t_tools *tools)
{
	if (!tools)
		return ;
	free_list(tools->commands);
	// free(tools->infile);
	// free(tools->outfile);
	free(tools->flag);
	free(tools);
}

void	free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}
