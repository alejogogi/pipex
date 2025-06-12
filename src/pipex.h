/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:22:39 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/12 17:11:55 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_tools
{
	int		infile;
	int		outfile;
	char	*abs_path;
	char	*path_env;
	char	*full_path;
}			t_tools;

// manage process.
void		second_child(t_tools *tools, int pipe[2], char **args, char **envp);
void		first_child(t_tools *tools, int pipe[2], char **args, char **envp);
void		create_child(t_tools *tools, char **args, char **envp);
void		create_process(char **args, char **envp);

// aux manage process.
char		*find_executable(char *cmd, char **envp, t_tools *tools);
char		*get_path_env(char **envp);

// free mem.
void		exit_error(t_tools *tools);
void		free_split(char **split);
void		free_aux(t_tools *tools, char *cmd_path, char **exec);
void		chec_empty_arg(char **args);

#endif