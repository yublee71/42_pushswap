/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:45:23 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 00:14:30 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_info
{
	int	min;
	int	i;
}	t_info;

static t_info	find_minimum_move(int move[4])
{
	int		cases[6];
	int		i;
	t_info	info;

	i = 0;
	info.min = INT_MAX;
	info.i = 0;
	cases[0] = move[0];
	cases[1] = move[2];
	cases[2] = move[0] + move[3];
	cases[3] = move[1];
	cases[4] = move[3];
	cases[5] = move[1] + move[2];
	while (i < 6)
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
	if (info.i == 0 || info.i == 1)
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
	else if (info.i == 2)
	{
		while (move[0]-- > 0)
			rotate_a(stack_a);
		while (move[3]-- > 0)
			reverse_rotate_b(stack_b);
	}
	else if (info.i == 3 || info.i == 4)
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
	else if (info.i == 5)
	{
		while (move[1]-- > 0)
			reverse_rotate_a(stack_a);
		while (move[2]-- > 0)
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

//move = {r_a, rr_a, r_b, rr_b}
static void	calculate_movements(t_stack **stack_a, t_stack **stack_b)
{
	int		move[4] = {0};
	int		min_move[4] = {0};
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
		// ft_printf("a: %d\n", a_size);
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
			min_info.i = info.min;
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

void	solve_big_numbers(t_stack **stack_a, t_stack **stack_b)
{

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if (is_stack_sorted(stack_b))
		swap_b(stack_b);
	while ((*stack_a)->prev->location > 3)
		calculate_movements(stack_a, stack_b);
	solve_three_a(stack_a);
}