/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:37:59 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:31 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The function ft_lstite() applies the function 'f' to the content of a
// linked-list`s node 'lst' and every succesor of that node.

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
