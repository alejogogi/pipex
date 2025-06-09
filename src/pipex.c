/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:01:00 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/09 16:03:04 by alejagom         ###   ########.fr       */
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

char	*find_executable(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	char	*abs_path;
	int		i;

	i = 0;
	abs_path = check_absolute_path(cmd);
	if (abs_path)
		return (abs_path);
	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	free_split(paths);
	return (NULL);
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
