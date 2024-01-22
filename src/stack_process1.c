/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:16:49 by yublee            #+#    #+#             */
/*   Updated: 2024/01/16 14:17:10 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_stack_print(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		ft_printf("empty\n");
	while (1 && temp)
	{
		ft_printf("number is: %d\n",temp->num);
		ft_printf("rank is: %d\n",temp->rank);
		ft_printf("location is: %d\n",temp->location);
		ft_printf("is it last node? : %d\n",temp->end);
		ft_printf("---------------\n");
		if (temp->end)
			break;
		temp = temp->next;
	}
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = content;
	new_node->rank = 0;
	new_node->location = 0;
	new_node->end = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack *ft_int_to_stack(int *input_int, int num_of_int)
{
	t_stack	*first_node;
//	t_stack	**head;
	t_stack	*current;
	t_stack	*next;
	int		i;

	i = 0;
	first_node = ft_stacknew(input_int[i++]);
	current = first_node;
//	ft_printf("here: %d\n", (*head)->num);
	while (i < num_of_int)
	{
		next = ft_stacknew(input_int[i++]);
		current->next = next;
		next->prev = current;
		next->location = i - 1;
		current = next;
	}
//	ft_printf("here: %d\n", (*head)->num);
	next->next = first_node;
	next->end = 1;
	(first_node)->prev = next;
	return (first_node);
}