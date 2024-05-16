/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:23:21 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 14:26:17 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_minimum_move(t_move *move)
{
	int		cases[4];
	int		i;

	if (move->ra > move->rb)
		cases[0] = move->ra;
	else
		cases[0] = move->rb;
	cases[1] = move->ra + move->rrb;
	if (move->rra > move->rrb)
		cases[2] = move->rra;
	else
		cases[2] = move->rrb;
	cases[3] = move->rra + move->rb;
	i = -1;
	move->min = INT_MAX;
	while (++i < 4)
	{
		if (cases[i] < move->min)
		{
			move->min = cases[i];
			move->i = i;
		}
	}
}

static void	search_from_b(t_stack **stack_b, t_stack *current_a, t_move *move)
{
	int		b_size;
	t_stack	*current_b;

	if (*stack_b)
	{
		current_b = (*stack_b);
		b_size = (*stack_b)->prev->location;
		if (find_minimum(stack_b)->rank > current_a->rank)
			while (current_b->prev->rank > current_b->rank)
				current_b = current_b->next;
		else if (find_maximum(stack_b)->rank < current_a->rank)
			while (current_b->prev->rank > current_b->rank)
				current_b = current_b->next;
		else
		{
			while (current_b->rank > current_a->rank
				|| current_b->prev->rank < current_a->rank)
				current_b = current_b->next;
		}
		move->rb = (current_b)->location - 1;
		move->rrb = b_size - (current_b)->location + 1;
	}
}

t_move	calculate_move(t_stack **stack_a, t_stack **stack_b)
{
	t_move	move;
	t_move	min_move;
	int		a_size;
	int		min;
	t_stack	*current_a;

	current_a = (*stack_a);
	min = INT_MAX;
	while (*stack_a)
	{
		a_size = (*stack_a)->prev->location;
		move.ra = (current_a)->location - 1;
		move.rra = a_size - (current_a)->location + 1;
		search_from_b(stack_b, current_a, &move);
		find_minimum_move(&move);
		if (move.min < min)
		{
			min = move.min;
			min_move = move;
		}
		if (current_a->end == 1)
			break ;
		current_a = current_a->next;
	}
	return (min_move);
}
