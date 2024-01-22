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

void	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack *temp;
	t_stack *temp2;
	t_stack *loc_temp;

	if (*stack_from == NULL)
		return ;
	temp = *stack_from;
	if (!temp->end)
	{
		(temp->prev)->next = temp->next;
		(temp->next)->prev = temp->prev;
		*stack_from = temp->next;
		loc_temp = *stack_from;
		while (!loc_temp->end)
		{
			loc_temp->location -= 1;
			loc_temp = loc_temp->next;
		}
		loc_temp->location -= 1;
	}
	else
	{
		*stack_from = NULL;
		temp->end = 0;
	}
	if (*stack_to != NULL)
	{
		loc_temp = *stack_to;
		while (!loc_temp->end)
		{
			loc_temp->location += 1;
			loc_temp = loc_temp->next;
		}
		loc_temp->location += 1;
		temp2 = *stack_to;
		temp->next= temp2;
		temp->prev= temp2->prev;
		(temp2->prev)->next = temp;
		temp2->prev= temp;
		*stack_to = temp;
	}
	else
	{
		*stack_to = temp;
		temp->next = temp;
		temp->prev = temp;
		temp->end = 1;
	}
	ft_printf("<<p>>\n");
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	temp->location = (temp->prev)->location;
	temp = temp->next;
	while (!temp->end)
	{
		temp->location -= 1;
		temp = temp->next;
	}
	temp->location -= 1;
	temp->end = 0;
	(*stack)->end = 1;
	*stack = (*stack)->next;
	ft_printf("<<r>>\n");
}

void	ft_reverse_rotate(t_stack **stack)
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
	*stack=(*stack)->prev;
	ft_printf("<<rr>>\n");
}

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
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
	if (second->end)
	{
		second->end = 0;
		first->end = 1;
	}
	*stack = temp->prev;
	ft_printf("<<s>>\n");
}