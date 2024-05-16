/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:44 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 17:53:44 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->end)
		return (0);
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
	return (1);
}

void	rotate_a(t_stack **stack_a)
{
	if (*stack_a && ft_rotate(stack_a))
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	if (*stack_b && ft_rotate(stack_b))
		ft_printf("rb\n");
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b && ft_rotate(stack_a) && ft_rotate(stack_b))
		ft_printf("rr\n");
}
