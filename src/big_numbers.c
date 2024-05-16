/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:45:23 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 15:32:31 by yublee           ###   ########.fr       */
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

static void	put_min_to_top(t_stack **stack)
{
	int		a_size;
	t_stack	*min_node;
	int		ra;
	int		rra;

	min_node = find_minimum(stack);
	a_size = (*stack)->prev->location;
	ra = (min_node)->location - 1;
	rra = a_size - (min_node)->location + 1;
	if (ra < rra)
		while (ra-- > 0)
			rotate_a(stack);
	else
		while (rra-- > 0)
			reverse_rotate_a(stack);
}

static void	push_all_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a && *stack_b)
	{
		if (find_maximum(stack_a)->rank < (*stack_b)->rank
			|| find_minimum(stack_a)->rank > (*stack_b)->rank)
			put_min_to_top(stack_a);
		else
			while (((*stack_a)->rank < (*stack_b)->rank)
				|| ((*stack_a)->prev->rank > (*stack_b)->rank))
				reverse_rotate_a(stack_a);
		push_a(stack_a, stack_b);
	}
	put_min_to_top(stack_a);
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
	while ((*stack_a)->prev->location > 3)
	{
		min_move = calculate_move(stack_a, stack_b);
		if (min_move.i == 0 || min_move.i == 1)
			push_to_b_ra(stack_a, stack_b, min_move);
		else
			push_to_b_rra(stack_a, stack_b, min_move);
	}
	solve_three_a(stack_a);
	push_all_back_to_a(stack_a, stack_b);
}
