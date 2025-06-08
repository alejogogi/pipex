/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:04:06 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/08 23:10:59 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_aux(t_tools *tools, char *cmd_path, char **exec)
{
	free(cmd_path);
	free_split(exec);
	exit_error(tools);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	exit_error(t_tools *tools)
{
	if (tools)
	{
		if (tools->infile >= 0)
			close(tools->infile);
		if (tools->outfile >= 0)
			close(tools->outfile);
		free(tools);
	}
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
