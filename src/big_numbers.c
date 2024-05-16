/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:45:23 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 14:25:49 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b_ra(t_stack **stack_a, t_stack **stack_b, t_move move)
{
	if (move.i == 0)
	{
		while (move.rb > 0 && move.ra > 0)
		{
			rotate_ab(stack_a, stack_b);
			move.ra--;
			move.rb--;
		}
		while (move.ra-- > 0)
			rotate_a(stack_a);
		while (move.rb-- > 0)
			rotate_b(stack_b);
	}
	else if (move.i == 1)
	{
		while (move.ra-- > 0)
			rotate_a(stack_a);
		while (move.rrb-- > 0)
			reverse_rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

static void	push_to_b_rra(t_stack **stack_a, t_stack **stack_b, t_move move)
{
	if (move.i == 2)
	{
		while (move.rrb > 0 && move.rra > 0)
		{
			reverse_rotate_ab(stack_a, stack_b);
			move.rra--;
			move.rrb--;
		}
		while (move.rra-- > 0)
			reverse_rotate_a(stack_a);
		while (move.rrb-- > 0)
			reverse_rotate_b(stack_b);
	}
	else if (move.i == 3)
	{
		while (move.rra-- > 0)
			reverse_rotate_a(stack_a);
		while (move.rb-- > 0)
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

static void	push_all_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		rb;
	int		rrb;
	t_stack	*max_node;
	int		b_size;

	b_size = (*stack_b)->prev->location;
	max_node = find_maximum(stack_b);
	rb = (max_node)->location - 1;
	rrb = b_size - (max_node)->location + 1;
	if (rb < rrb)
		while (rb--)
			rotate_b(stack_b);
	else
		while (rrb--)
			reverse_rotate_b(stack_b);
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	solve_big_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_move	min_move;

	if (is_stack_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if (is_stack_sorted(stack_b))
		swap_b(stack_b);
	while ((*stack_a))
	{
		min_move = calculate_move(stack_a, stack_b);
		if (min_move.i == 0 || min_move.i == 1)
			push_to_b_ra(stack_a, stack_b, min_move);
		else
			push_to_b_rra(stack_a, stack_b, min_move);
	}
	push_all_back_to_a(stack_a, stack_b);
}
