/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:19:14 by gita              #+#    #+#             */
/*   Updated: 2025/07/04 18:22:51 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	p2a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->len > 0)
	{
		i = stack_a->len;
		while (i >= 1)
		{
			stack_a->arr[i] = stack_a->arr[i - 1];
			i--;
		}
		stack_a->arr[i] = stack_b->arr[i];
		stack_a->len++;
		while (i < stack_b->len - 1)
		{
			stack_b->arr[i] = stack_b->arr[i + 1];
			i++;
		}
		stack_b->len--;
		write(1, "pa\n", 3);
	}
}

void	p2b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->len > 0)
	{
		i = stack_b->len;
		while (i >= 1)
		{
			stack_b->arr[i] = stack_b->arr[i - 1];
			i--;
		}
		stack_b->arr[i] = stack_a->arr[i];
		stack_b->len++;
		while (i < stack_a->len - 1)
		{
			stack_a->arr[i] = stack_a->arr[i + 1];
			i++;
		}
		stack_a->len--;
		write(1, "pb\n", 3);
	}
}