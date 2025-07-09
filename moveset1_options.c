/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset1_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:15:17 by gita              #+#    #+#             */
/*   Updated: 2025/07/09 11:35:32 by gita             ###   ########.fr       */
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
		if (stack.arr[0] > stack.arr[1])
			sa(stack);
	}
}

static void	strategic_push(t_stack *a, t_stack *b)
{
	t_cost	best;

	best = best_move(a, b);
	duo_roll(a, b, &best);
	bring_to_top(best.a_index, best.a_steps, a, STACK_A);
	bring_to_top(best.b_index, best.b_steps, b, STACK_B);
	p2a(a, b);
}

static void	high_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;
	int	steps_of_min;

	while (stack_a->len > 3)
		p2b(stack_a, stack_b);
	three_elem(*stack_a);
	while (stack_b->len > 0)
		strategic_push(stack_a, stack_b);
	min_pos = min_value_pos(*stack_a);
	if (min_pos != 0)
	{
		steps_of_min = steps_to_top(*stack_a, min_pos);
		bring_to_top(min_pos, steps_of_min, stack_a, STACK_A);
	}
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
		high_stack(a, b);
	if (stack_is_sorted(*a))
		return (1);
	return (0);
}
