/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:45:23 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 13:43:38 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_info	find_minimum_move(t_move move)
{
	int		cases[4];
	int		i;
	t_info	info;

	if (move.ra > move.rb)
		cases[0] = move.ra;
	else
		cases[0] = move.rb;
	cases[1] = move.ra + move.rrb;
	if (move.rra > move.rrb)
		cases[2] = move.rra;
	else
		cases[2] = move.rrb;
	cases[3] = move.rra + move.rb;
	i = -1;
	info.min = INT_MAX;
	while (++i < 4)
	{
		if (cases[i] < info.min)
		{
			info.min = cases[i];
			info.i = i;
		}
	}
	return (info);
}

static void	action_execute(t_stack **stack_a, t_stack **stack_b, t_info info, t_move move)
{
	if (info.i == 0)
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
	else if (info.i == 1)
	{
		while (move.ra-- > 0)
			rotate_a(stack_a);
		while (move.rrb-- > 0)
			reverse_rotate_b(stack_b);
	}
	else if (info.i == 2)
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
	else if (info.i == 3)
	{
		while (move.rra-- > 0)
			reverse_rotate_a(stack_a);
		while (move.rb-- > 0)
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

static void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_move	move;
	t_move	min_move;
	int		a_size;
	int		b_size;
	t_info	info;
	t_info	min_info;
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = (*stack_a);
	min_info.min = INT_MAX;
	while (*stack_a)
	{
		a_size = (*stack_a)->prev->location;
		move.ra = (current_a)->location - 1;
		move.rra = a_size - (current_a)->location + 1;
		if (*stack_b)
		{
			current_b = (*stack_b);
			b_size = (*stack_b)->prev->location;
			if (find_minimum(stack_b) > current_a->rank)
				while (current_b->prev->rank > current_b->rank)
					current_b = current_b->next;
			else if (find_maximum(stack_b) < current_a->rank)
				while (current_b->prev->rank > current_b->rank)
					current_b = current_b->next;
			else
			{
				while (current_b->rank > current_a->rank
					|| current_b->prev->rank < current_a->rank)
					current_b = current_b->next;
			}
			move.rb = (current_b)->location - 1;
			move.rrb = b_size - (current_b)->location + 1;
		}
		info = find_minimum_move(move);
		if (info.min < min_info.min)
		{
			min_info = info;
			min_move = move;
		}
		if (current_a->end == 1)
			break ;
		current_a = current_a->next;
	}
	action_execute(stack_a, stack_b, min_info, min_move);
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		rb;
	int		rrb;
	t_stack	*current;
	t_stack	*max_node;
	int		b_size;
	int		max;

	max = INT_MIN;
	current = (*stack_b);
	b_size = (*stack_b)->prev->location;
	while (1)
	{
		if (current->rank > max)
		{
			max = current->rank;
			max_node = current;
		}
		if (current->end == 1)
			break ;
		current = current->next;
	}
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
	if (is_stack_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if (is_stack_sorted(stack_b))
		swap_b(stack_b);
	while ((*stack_a))
		push_to_b(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}
