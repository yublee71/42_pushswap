/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:16:49 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 13:18:04 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int num, int rank)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit_with_error("malloc\n", 1, NULL);
	new_node->num = num;
	new_node->rank = rank;
	new_node->location = 1;
	new_node->end = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*int_to_stack(int *input_int, int *rank, int num_of_int)
{
	t_stack	*first_node;
	t_stack	*current;
	t_stack	*next;
	int		i;

	i = 0;
	first_node = stack_new(input_int[i], rank[i]);
	current = first_node;
	while (++i < num_of_int)
	{
		next = stack_new(input_int[i], rank[i]);
		current->next = next;
		next->prev = current;
		next->location = i + 1;
		current = next;
	}
	if (i > 1)
	{
		next->next = first_node;
		next->end = 1;
		(first_node)->prev = next;
	}
	free(input_int);
	free(rank);
	return (first_node);
}
