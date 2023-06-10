/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:05:23 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:30 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isalnum() function tests for any character for which ft_isalpha() 
// or ft_isdigit() is true.

#include "../includes/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		return (1);
	return (0);
}
