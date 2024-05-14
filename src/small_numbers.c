/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:24:09 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 21:47:57 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three(t_stack **stack_a)
{
	int		rank1;
	int		rank2;
	int		rank3;

	if (((*stack_a)->prev)->location != 3)
		return ;
	rank1 = (*stack_a)->rank;
	rank2 = ((*stack_a)->next)->rank;
	rank3 = ((*stack_a)->prev)->rank;
	if (rank1 < rank3 && rank3 < rank2)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	if (rank2 < rank1 && rank1 < rank3)
		swap_a(stack_a);
	if (rank3 < rank1 && rank1 < rank2)
		reverse_rotate_a(stack_a);
	if (rank2 < rank3 && rank3 < rank1)
		rotate_a(stack_a);
	if (rank3 < rank2 && rank2 < rank1)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	solve_til_five(t_stack **stack_a, t_stack **stack_b)
{
	if (is_stack_sorted(stack_a))
		return ;
	while (((*stack_a)->prev)->location > 3)
		push_b(stack_a, stack_b);
	solve_three(stack_a);
	if (!is_stack_sorted(stack_b))
		swap_b(stack_b);
	if ((*stack_b) && (*stack_b)->rank == 1)
		push_a(stack_a, stack_b);
	if ((*stack_b) && (*stack_b)->rank == 2)
	{
		rotate_a(stack_a);
		push_a(stack_a, stack_b);
		if ((*stack_b) && (*stack_b)->rank == 3)
		{
			rotate_a(stack_a);
			push_a(stack_a, stack_b);
		}
	}
	while (*stack_b)
	{
		while ((*stack_b)->rank - ((*stack_a)->prev)->rank != 1)
			reverse_rotate_a(stack_a);
		push_a(stack_a, stack_b);
	}
	while ((*stack_a)->rank != 1)
		rotate_a(stack_a);
}
