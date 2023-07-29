/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:37:48 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 10:55:21 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../../includes/libft.h"

char	*get_next_line(int fd);
char	*get_and_return_nl(char **buffer, int *eof);
char	*read_line_to_buffer(int fd, char **buffer, int *eof);
char	*free_buffer(char **buffer);

char	*gnl_strjoin(char *dst, char *src);

#endif
