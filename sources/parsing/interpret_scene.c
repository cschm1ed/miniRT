/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:20:21 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:55:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int interpret_lightsource(char **str, t_data *data)
{
	char *split;

	split = ft_split(str[0]);
	while (split != NULL)
	{
		data->scene->
	}
	split = ft_split()
	return (SUCCESS);
}




L -40.0,50.0,0.0 	0.6 	10,0,255




void addNode(ListNode** head, void* data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
	} else {
		ListNode* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}