#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	if (ft_reverse_rotate(stack_a))
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (ft_reverse_rotate(stack_b))
		ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_reverse_rotate(stack_a) && ft_reverse_rotate(stack_b))
		ft_printf("rrr\n");
}

bool	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->end)
		return (0);
	temp = *stack;
	while (!temp->end)
	{
		temp->location++;
		temp = temp->next;
	}
	(temp->prev)->end = 1;
	(temp)->location = 0;
	(temp)->end = 0;
	*stack=(*stack)->prev;
	return (1);
}