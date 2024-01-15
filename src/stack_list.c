#include "push_swap.h"

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