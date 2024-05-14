/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:02:08 by yublee            #+#    #+#             */
/*   Updated: 2024/05/14 22:32:13 by yublee           ###   ########.fr       */
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

typedef struct s_id
{
	unsigned int	identifier;
	char			*answer;
}	t_id;

int		*ft_input_convert_to_int(int argc, char *argv[]);
void	ft_input_duplicate_check(int *input_int, int argc);

t_stack	*ft_int_to_stack(int *input_int, int *rank, int argc);
t_stack	*ft_stacknew(int num, int rank);
bool	is_stack_sorted(t_stack **stack);
void	ft_stack_print(t_stack **stack);

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

int		*ft_rank(int *input_int, int size);
void	solve_three_a(t_stack **stack_a);
void	solve_three_b(t_stack **stack_a);
void	solve_til_six(t_stack **stack_a, t_stack **stack_b);

#endif
