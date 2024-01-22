/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:02:08 by yublee            #+#    #+#             */
/*   Updated: 2024/01/11 20:45:06 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
	int				rank;
	int				location;
	bool			end;
}	t_stack;

int		*ft_input_convert_to_int(int argc, char *argv[]);
void	ft_input_duplicate_check(int *input_int, int argc);
t_stack	*ft_int_to_stack(int *input_int, int argc);
t_stack	*ft_stacknew(int content);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_from, t_stack **stack_to);
void	ft_stack_print(t_stack **stack);

#endif
