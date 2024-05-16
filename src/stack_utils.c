/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:10:08 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 13:18:29 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp && !temp->end)
	{
		if ((temp->next) && temp->rank > (temp->next)->rank)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	stack_print(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		ft_printf("empty\n");
	while (temp)
	{
		ft_printf("number is: %d\n", temp->num);
		ft_printf("rank is: %d\n", temp->rank);
		ft_printf("location is: %d\n", temp->location);
		ft_printf("is it last node? : %d\n", temp->end);
		ft_printf("---------------\n");
		if (temp->end)
			break ;
		temp = temp->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current && !current->end)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

int	find_minimum(t_stack **stack)
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

int	find_maximum(t_stack **stack)
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
