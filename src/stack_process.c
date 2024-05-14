/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:16:49 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 23:39:25 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

bool	is_stack_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (!temp->end)
	{
		if (temp->rank > (temp->next)->rank)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_stack_print(t_stack **stack)
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

t_stack	*ft_stacknew(int num, int rank)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->rank = rank;
	new_node->location = 1;
	new_node->end = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_int_to_stack(int *input_int, int *rank, int num_of_int)
{
	t_stack	*first_node;
	t_stack	*current;
	t_stack	*next;
	int		i;

	i = 0;
	first_node = ft_stacknew(input_int[i], rank[i]);
	i++;
	current = first_node;
	while (i < num_of_int)
	{
		next = ft_stacknew(input_int[i], rank[i]);
		current->next = next;
		next->prev = current;
		next->location = i + 1;
		current = next;
		i++;
	}
	next->next = first_node;
	next->end = 1;
	(first_node)->prev = next;
	free(input_int);
	free(rank);
	return (first_node);
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
