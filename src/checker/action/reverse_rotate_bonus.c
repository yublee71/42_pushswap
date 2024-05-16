/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:39 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 16:55:22 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static bool	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->end)
		return (0);
	temp = *stack;
	while (!temp->end)
	{
		temp->location++;
		temp = temp->next;
	}
	(temp->prev)->end = 1;
	(temp)->location = 1;
	(temp)->end = 0;
	*stack = (*stack)->prev;
	return (1);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	if (*stack_a)
		ft_reverse_rotate(stack_a);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (*stack_b)
		ft_reverse_rotate(stack_b);
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}
