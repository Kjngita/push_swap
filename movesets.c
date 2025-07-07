/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:19:04 by gita              #+#    #+#             */
/*   Updated: 2025/07/07 20:12:49 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int	stack_is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while ((i < stack.len - 1))
	{
		if (stack.arr[i] > stack.arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	three_elem(t_stack stack)
{
	while (stack_is_sorted(stack) == 0)
	{
		if (stack.arr[1] > stack.arr[0] && stack.arr[1] > stack.arr[2])
			rra(stack);
		if (stack.arr[0] > stack.arr[1] && stack.arr[0] > stack.arr[2])
			ra(stack);
		if (stack.arr[1] < stack.arr[0] && stack.arr[1] < stack.arr[2]
			|| stack.arr[0] < stack.arr[1] && stack.arr[0] < stack.arr[2])
			sa(stack);
	}
}

static void	strategic_push(t_stack *a, t_stack *b)
{
	//find_cheapest, bring both to top
	p2a(a, b);
}

static void	high_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
		p2b(&stack_a, &stack_b);
	three_elem(*stack_a);
	while (stack_b->len > 0)
		stategic_push(&stack_a, &stack_b);
}

int	algo_worked(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(*a))
		return (1);
	else if (a->len == 2)
	{
		if (a->arr[0] > a->arr[1])
			sa(*a);
		return (1);
	}
	else if (a->len == 3)
		three_elem(*a);
	else
		high_stack(&a, &b);
	if (stack_is_sorted(*a))
		return (1);
	return (0);
}