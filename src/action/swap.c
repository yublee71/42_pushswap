#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	if (ft_swap(stack_a))
		ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	if (ft_swap(stack_b))
		ft_printf("sb\n");
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_swap(stack_a) && ft_swap(stack_b))
		ft_printf("ss\n");
}

bool	ft_swap(t_stack **stack)
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
	value = temp->location;
	temp->location = (temp->next)->location;
	(temp->next)->location = value;
	return (1);
}
/*
void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
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
	second->location = -1;
	first->location = 0;
	if (second->end)
	{
		second->end = -1;
		first->end = 0;
	}
	*stack = temp->prev;
	ft_printf("<<s>>\n");
}
*/
