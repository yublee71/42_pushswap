/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:49 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 16:56:39 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static bool	ft_swap(t_stack **stack)
{
	int		value;
	t_stack	*temp;

	temp = *stack;
	if (temp->end)
		return (0);
	value = temp->num;
	temp->num = (temp->next)->num;
	(temp->next)->num = value;
	value = temp->rank;
	temp->rank = (temp->next)->rank;
	(temp->next)->rank = value;
	return (1);
}

void	swap_a(t_stack **stack_a)
{
	if (*stack_a)
		ft_swap(stack_a);
}

void	swap_b(t_stack **stack_b)
{
	if (*stack_b)
		ft_swap(stack_b);
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}
