/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:51:45 by gita              #+#    #+#             */
/*   Updated: 2025/07/03 22:07:11 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	rotate(t_stack stack)
{
	int	i;
	int	temp;

	temp = stack.arr[0];
	i = 0;
	while (i < stack.len - 1)
	{
		stack.arr[i] = stack.arr[i + 1];
		i++;
	}
	stack.arr[i] = temp;
}

void	ra(t_stack stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack stack_a, t_stack stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}