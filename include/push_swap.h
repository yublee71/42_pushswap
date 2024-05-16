/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:02:08 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 14:53:25 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
	int				rank;
	int				location;
	bool			end;
}	t_stack;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	min;
	int	i;
}	t_move;

void	input_convert_to_int(int argc, char *argv[], int *input_int);
void	input_duplicate_check(int *input_int, int argc);

t_stack	*int_to_stack(int *input_int, int *rank, int argc);
t_stack	*stack_new(int num, int rank);

void	solve_three_a(t_stack **stack_a);
void	solve_til_six(t_stack **stack_a, t_stack **stack_b);
void	solve_big_numbers(t_stack **stack_a, t_stack **stack_b);
t_move	calculate_move(t_stack **stack_a, t_stack **stack_b);

bool	is_stack_sorted(t_stack **stack);
void	stack_print(t_stack **stack);
void	free_stack(t_stack **stack);
t_stack	*find_minimum(t_stack **stack);
t_stack	*find_maximum(t_stack **stack);

int		*ft_rank(int *input_int, int size);
long	ft_long_atoi(const char *nptr);
void	exit_with_error(const char *str, int exit_no, int *int_input);

void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);

void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

#endif
