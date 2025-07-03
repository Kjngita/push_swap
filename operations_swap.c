/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:06:46 by gita              #+#    #+#             */
/*   Updated: 2025/07/03 20:18:09 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	swap(int *arr)
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void	sa(t_stack stack_a)
{
	if (stack_a.len > 1)
	{
		swap(stack_a.arr);
		write(1, "sa\n", 3);
	}
}
void	sb(t_stack stack_b)
{
	if (stack_b.len > 1)
	{
		swap(stack_b.arr);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack stack_a, t_stack stack_b)
{
	if (stack_a.len > 1 && stack_b.len > 1)
	{
		swap(stack_a.arr);
		swap(stack_b.arr);
		write(1, "ss\n", 3);
	}
}