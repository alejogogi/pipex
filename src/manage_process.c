/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:34:46 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/08 23:13:27 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_child(t_tools *tools, int pipe[2], char **args, char **envp)
{
	char	*cmd_path;
	char	**exe_cmd;

	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0]);
	dup2(tools->outfile, STDOUT_FILENO);
	close(tools->outfile);
	exe_cmd = ft_split(args[3], ' ');
	if (!exe_cmd)
		exit_error(tools);
	cmd_path = find_executable(exe_cmd[0], envp);
	if (!cmd_path)
	{
		free_split(exe_cmd);
		exit_error(tools);
	}
	if (execve(cmd_path, exe_cmd, envp) == -1)
		free_aux(tools, cmd_path, exe_cmd);
}

void	first_child(t_tools *tools, int pipe[2], char **args, char **envp)
{
	char	*cmd_path;
	char	**exec_cmd;

	close(pipe[0]);
	dup2(tools->infile, STDIN_FILENO);
	close(tools->infile);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	exec_cmd = ft_split(args[2], ' ');
	if (!exec_cmd)
		exit_error(tools);
	cmd_path = find_executable(exec_cmd[0], envp);
	if (!cmd_path)
	{
		free_split(exec_cmd);
		exit_error(tools);
	}
	if (execve(cmd_path, exec_cmd, envp) == -1)
		free_aux(tools, cmd_path, exec_cmd);
}

void	create_child(t_tools *tools, char **args, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fd) == -1)
		exit_error(tools);
	pid1 = fork();
	if (pid1 < 0)
		exit_error(tools);
	if (pid1 == 0)
		first_child(tools, pipe_fd, args, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit_error(tools);
	if (pid2 == 0)
		second_child(tools, pipe_fd, args, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	create_process(char **args, char **envp)
{
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools)
		exit_error(NULL);
	tools->infile = open(args[1], O_RDONLY);
	if (tools->infile < 0)
		exit_error(tools);
	tools->outfile = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tools->outfile < 0)
	{
		exit_error(tools);
	}
	create_child(tools, args, envp);
	close(tools->infile);
	close(tools->outfile);
	free(tools);
}
