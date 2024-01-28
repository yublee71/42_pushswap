#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	if (ft_rotate(stack_a))
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	if (ft_rotate(stack_b))
		ft_printf("rb\n");
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_rotate(stack_a) && ft_rotate(stack_b))
		ft_printf("rr\n");
}

bool	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->end)
		return (0);
	temp = *stack;
	temp->location = (temp->prev)->location;
	temp = temp->next;
	while (!temp->end)
	{
		temp->location -= 1;
		temp = temp->next;
	}
	temp->location -= 1;
	temp->end = 0;
	(*stack)->end = 1;
	*stack = (*stack)->next;
	return (1);
}