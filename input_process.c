/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:12:26 by yublee            #+#    #+#             */
/*   Updated: 2024/01/10 19:16:26 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

bool	ft_input_check(int argc, char *argv[])
{
	if (argc == 1)
	//give prompt back??
		exit (1);
	else
	//all integer check
		printf("%s",argv[0]);
	return(0);
}