/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:19:28 by gafreire          #+#    #+#             */
/*   Updated: 2025/05/10 20:50:44 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*read_newline(int fd, char *line_buffer, char *buffer);
char	*extract_line(char *line_buffer);
char	*extract_remaining(char *line_buffer);
char	*gt_strjoin(char *s1, char *s2);
char	*gt_strchr(char *s, int c);
char	*gt_strdup(char *s1);
size_t	gt_strlen(char *s);

#endif