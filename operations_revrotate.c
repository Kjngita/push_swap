/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_revrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:11:26 by gita              #+#    #+#             */
/*   Updated: 2025/07/04 18:46:18 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	rev_rot(t_stack stack)
{
	int	i;
	int temp;

	i = stack.len - 1;
	temp = stack.arr[i];
	while (i > 0)
	{
		stack.arr[i] = stack.arr[i - 1];
		i--;
	}
	stack.arr[i] = temp;
}

void	rra(t_stack stack_a)
{
	rev_rot(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack stack_b)
{
	rev_rot(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack stack_a, t_stack stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
	write(1, "rrr\n", 4);
}
