/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:14:29 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:31 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The function ft_lstlast() returns the last node of the linked-list 'lst'.

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
