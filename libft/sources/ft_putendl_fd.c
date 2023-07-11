/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:19:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:33 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_putendl_fd() outputs a newline-character to filedescriptor 'fd'.

#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return ;
}
