/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:22:39 by alejogogi         #+#    #+#             */
/*   Updated: 2025/06/02 20:49:43 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_node
{
	char			**agrs;
	struct s_node	*next;
}					t_node;

typedef struct s_tools
{
	t_node			*commands;
	char			*infile;
	char			*outfile;
	char			*flag;
	char			**temp;
	int				size;
}					t_tools;
// funciones auxiliares
void				free_split(char **args);
void				check_file(int ln, char **args, t_tools *tools);
void				parc_command(int ln, char **args, t_tools *tools);
void				add_node(t_tools *tools, char **str);
void				add_node_aux(t_tools *tools, t_node *temp);

// liberar memoria
void				free_tools(t_tools *tools);
void				free_split(char **temp);
void				free_list(t_node *head);

#endif