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
	while (1)
	{
		ft_printf("---------------\n");
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

t_stack	**ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	temp->location = (temp->prev)->location;
	temp = temp->next;
	while (1)
	{
		temp->location -= 1;
		if (temp->end)
			break;
		temp = temp->next;
	}
	temp->end = 0;
	(*stack)->end = 1;
	return(&((*stack)->next));
}

t_stack	**ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (!temp->end)
	{
		temp->location++;
		temp = temp->next;
	}
	(temp->prev)->end = 1;
	(temp)->location = 0;
	(temp)->end = 0;
	return(&((*stack)->prev));
}

t_stack **ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;
	t_stack	**new_stack;

	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	last = (*stack)->prev;
	last->next = second;
	second->next = first;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->prev = last;
	second->location = 0;
	first->location = 1;
	new_stack = &((*stack)->next);
	return (new_stack);
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