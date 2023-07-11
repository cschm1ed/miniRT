/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:00:52 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 10:55:39 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/**
 * read_line_to_buffer - reads a line from a file descriptor and appends it to a buffer
 * @fd: the file descriptor to read from
 * @buffer: pointer to the buffer to append to
 * @eof: pointer to the end of file flag
 * 
 * Reads a line from the given file descriptor and appends it to the buffer.
 * 
 * Return: a pointer to the updated buffer, or NULL if there is an error
 */


char	*read_line_to_buffer(int fd, char **buffer, int *eof)
{
	int		r_val;
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	r_val = read(fd, tmp, BUFFER_SIZE);
	if (r_val == 0)
	{	
		*eof = 1;
		return (free(tmp), *buffer);
	}
	if (r_val < 0)
		return (free(tmp), free(*buffer), NULL);
	if (r_val == 0 && *eof == 1)
		return (free(tmp), NULL);
	tmp[r_val] = 0;
	return (gnl_strjoin(*buffer, tmp));
}

/**
 * get_and_return_nl - finds and returns the newline character in the buffer
 * @buffer: pointer to the buffer containing the newline character
 * @eof: pointer to the end of file flag
 * 
 * Retrieves the newline character in the buffer and returns the line containing it.
 * 
 * Return: a pointer to the line containing the newline character, or NULL if there is an error
 */

char	*get_and_return_nl(char **buffer, int *eof)
{
	int		len_out;
	int		len_remainder;
	char	*nl;
	char	*out;

	nl = ft_strchr(*buffer, '\n');
	if (*eof == 1)
		nl = *buffer + ft_strlen(*buffer) - 1;
	len_out = nl - *buffer + 1;
	len_remainder = ft_strlen(nl + 1);
	out = malloc(sizeof(char) * len_out + 1);
	if (!out)
		return (free_buffer(buffer));
	out[len_out] = 0;
	ft_memcpy(out, *buffer, len_out);
	ft_memcpy(*buffer, nl + 1, len_remainder);
	buffer[0][len_remainder] = 0;
	return (out);
}

/**
 * get_next_line - reads a line from a file descriptor
 * @fd: the file descriptor to read from
 * 
 * Reads a line from the given file descriptor, up to a newline character or end of file.
 * Memory for the returned line is allocated and must be freed by the caller.
 * 
 * Return: a pointer to the read line, or NULL if there is an error or the end of file is reached
 */

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	int			eof;
	char		*out;

	eof = 0;
	if (fd < 0 || fd > 1024)
		return (NULL);
	while (1)
	{
		if (!buffer[fd] || !ft_strchr(buffer[fd], '\n'))
		{
			buffer[fd] = read_line_to_buffer(fd, buffer + fd, &eof);
			if (!buffer[fd])
				return (NULL);
		}
		if (*buffer[fd] == 0)
			return (free_buffer(buffer + fd));
		if (ft_strchr(buffer[fd], '\n') || eof == 1)
		{
			out = get_and_return_nl(buffer + fd, &eof);
			if (!out)
				return (free_buffer(buffer + fd));
			return (out);
		}
	}
}

/**
 * free_buffer - frees the memory allocated for the buffer
 * @buffer: pointer to the buffer to be freed
 * 
 * Frees the memory allocated for the buffer and sets the buffer pointer to NULL.
 * 
 * Return: NULL
 */

char	*free_buffer(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = 0;
	}
	return (NULL);
}
