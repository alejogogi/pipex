/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:01:00 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/12 17:14:01 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*check_absolute_path(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

char	*find_executable(char *cmd, char **envp, t_tools *tools)
{
	char	**paths;
	char	*temp;
	int		i;

	i = 0;
	tools->abs_path = check_absolute_path(cmd);
	if (tools->abs_path)
		return (tools->abs_path);
	tools->path_env = get_path_env(envp);
	if (!tools->path_env)
		return (NULL);
	paths = ft_split(tools->path_env, ':');
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		tools->full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(tools->full_path, X_OK) == 0)
			return (free_split(paths), tools->full_path);
		free(tools->full_path);
		i++;
	}
	return (free_split(paths), NULL);
}

void	check_empty_arg(char **args)
{
	char	**temp;

	temp = ft_split(args[2], ' ');
	if (!temp || !temp[0] || temp[0][0] == '\0')
	{
		ft_printf("Error\n");
		free_split(temp);
		return ;
	}
	free_split(temp);
	temp = ft_split(args[3], ' ');
	if (!temp || !temp[0] || temp[0][0] == '\0')
	{
		ft_printf("Error\n");
		free_split(temp);
		return ;
	}
	free_split(temp);
}

int	main(int ln, char **args, char **envp)
{
	if (ln != 5)
		return (ft_printf("Error\n"));
	check_empty_arg(args);
	create_process(args, envp);
	return (0);
}
