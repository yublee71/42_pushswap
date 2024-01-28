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

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_b, stack_a))
		ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_a, stack_b))
		ft_printf("pb\n");
}

bool	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack *temp;
	t_stack *temp2;
	t_stack *loc_temp;

	if (*stack_from == NULL)
		return (0);
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
	return (1);
}

