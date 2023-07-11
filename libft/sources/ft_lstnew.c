/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:40:51 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:32 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The function ft_lstnew() creates a new node of a linked_list, and sets the
// value of the member 'content' to the value of the provided argument
// 'content'.

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = ft_calloc(sizeof(t_list), 1);
	if (list == 0)
		return (0);
	list->content = content;
	list->next = 0;
	return (list);
}
