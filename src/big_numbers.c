/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:45:23 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 04:23:45 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_info	find_minimum_move(int move[4])
{
	int		cases[4];
	int		i;
	t_info	info;

	i = 0;
	info.min = INT_MAX;
	info.i = 0;
	if (move[0] > move[2])
		cases[0] = move[0];
	else
		cases[0] = move[2];
	cases[1] = move[0] + move[3];
	if (move[1] > move[3])
		cases[2] = move[1];
	else
		cases[2] = move[3];
	cases[3] = move[1] + move[2];
	while (i < 4)
	{
		if (cases[i] < info.min)
		{
			info.min = cases[i];
			info.i = i;
		}
		i++;
	}
	return (info);
}

static int	find_minimum(t_stack **stack)
{
	int		min;
	t_stack	*current;

	min = 0;
	if (*stack)
	{
		min = INT_MAX;
		current = *stack;
	}
	while (*stack)
	{
		if (current->rank < min)
			min = current->rank;
		if (current->end == 1)
			break ;
		current = current->next;
	}
	return (min);
}

static int	find_maximum(t_stack **stack)
{
	int		max;
	t_stack	*current;

	max = 0;
	if (*stack)
	{
		max = INT_MIN;
		current = *stack;
	}
	while (*stack)
	{
		if (current->rank > max)
			max = current->rank;
		if (current->end == 1)
			break ;
		current = current->next;
	}
	return (max);
}

static void	action_execute(t_stack **stack_a, t_stack **stack_b, t_info info, int move[4])
{
	if (info.i == 0)
	{
		while (move[2] > 0 && move[0] > 0)
		{
			rotate_ab(stack_a, stack_b);
			move[0]--;
			move[2]--;
		}
		while (move[0]-- > 0)
			rotate_a(stack_a);
		while (move[2]-- > 0)
			rotate_b(stack_b);
	}
	else if (info.i == 1)
	{
		while (move[0]-- > 0)
			rotate_a(stack_a);
		while (move[3]-- > 0)
			reverse_rotate_b(stack_b);
	}
	else if (info.i == 2)
	{
		while (move[3] > 0 && move[1] > 0)
		{
			reverse_rotate_ab(stack_a, stack_b);
			move[1]--;
			move[3]--;
		}
		while (move[1]-- > 0)
			reverse_rotate_a(stack_a);
		while (move[3]-- > 0)
			reverse_rotate_b(stack_b);
	}
	else if (info.i == 3)
	{
		while (move[1]-- > 0)
			reverse_rotate_a(stack_a);
		while (move[2]-- > 0)
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

//move = {r_a, rr_a, r_b, rr_b}
static void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		move[4];
	int		min_move[4];
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
		move[0] = (current_a)->location - 1;
		move[1] = a_size - (current_a)->location + 1;
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
			move[2] = (current_b)->location - 1;
			move[3] = b_size - (current_b)->location + 1;
		}
		info = find_minimum_move(move);
		if (info.min < min_info.min)
		{
			min_info.min = info.min;
			min_info.i = info.i;
			min_move[0] = move[0];
			min_move[1] = move[1];
			min_move[2] = move[2];
			min_move[3] = move[3];
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
