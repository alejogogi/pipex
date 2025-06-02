/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:14:24 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/02 21:06:58 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(int ln, char **args, t_tools *tools)
{
	if (ft_strncmp(args[1], "here_doc", 9) == 0)
	{
		tools->flag = args[2];
		tools->infile = NULL;
	}
	else
	{
		tools->flag = NULL;
		tools->infile = args[2];
	}
	tools->outfile = args[ln - 1];
}

void	parc_command(int ln, char **args, t_tools *tools)
{
	int		i;
	char	**temp;

	tools->size = 0;
	if (tools->infile)
		i = 2;
	else
		i = 3;
	while (i < ln - 1)
	{
		temp = ft_split(args[i], ' ');
		add_node(tools, temp);
		free_split(temp);
		i++;
	}
}

void	add_node(t_tools *tools, char **str)
{
	t_node	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(sizeof(t_node));
	while (str[i])
		i++;
	temp->agrs = malloc(sizeof(char *) * (i + 1));
	if (!temp->agrs)
	{
		free(temp);
		exit(1);
	}
	while (j < i)
	{
		temp->agrs[j] = ft_strdup(str[j]);
		j++;
	}
	temp->agrs[i] = NULL;
	temp->next = NULL;
	add_node_aux(tools, temp);
}

void	add_node_aux(t_tools *tools, t_node *temp)
{
	t_node	*new_node;

	if (!tools->commands)
		tools->commands = temp;
	else
	{
		new_node = tools->commands;
		while (new_node->next)
			new_node = new_node->next;
		new_node->next = temp;
	}
	tools->size++;
}
