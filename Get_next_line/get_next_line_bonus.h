/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:53:00 by gemartin          #+#    #+#             */
/*   Updated: 2023/06/18 19:42:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFFER_SIZE 10000
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(char *s1);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_free(char **str);

char	*clean_storage(char *storage);
char	*ft_free(char **str);
char	*new_line(char *storage);
char	*read_file(int fd, char *storage);
#endif
