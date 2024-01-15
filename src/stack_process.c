#include "push_swap.h"
#include <stdio.h>

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = content;
	new_node->rank = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	**ft_rotate(t_stack **stack)
{
	return(&((*stack)->next));
}

t_stack	**ft_reverse_rotate(t_stack **stack)
{
	return(&((*stack)->prev));
}

t_stack **ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;
	t_stack	**new_stack;

	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	last = (*stack)->prev;
	last->next = second;
	second->next = first;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->prev = last;
	new_stack = &((*stack)->next);
	return (new_stack);
}