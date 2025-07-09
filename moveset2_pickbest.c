/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset2_pickbest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:15:40 by gita              #+#    #+#             */
/*   Updated: 2025/07/09 12:17:36 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int	max_value(t_stack stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack.arr[i];
	while (i < stack.len)
	{
		if (max < stack.arr[i])
			max = stack.arr[i];
		i++;
	}
	return (max);
}

int	min_value_pos(t_stack stack)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	pos = 0;
	min = stack.arr[i];
	while (i < stack.len)
	{
		if (min > stack.arr[i])
		{
			min = stack.arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static int	target_index(t_stack *stack_a, int b_value)
{
	int	i;
	int	pos;
	int	target;
	int	min_pos;

	min_pos = min_value_pos(*stack_a);
	if (b_value > max_value(*stack_a) || b_value < stack_a->arr[min_pos])
		pos = min_value_pos(*stack_a);
	else
	{
		i = 0;
		pos = 0;
		target = INT_MAX;
		while (i < stack_a->len)
		{
			if (stack_a->arr[i] > b_value && stack_a->arr[i] < target)
			{
				pos = i;
				target = stack_a->arr[i];
			}
			i++;
		}
	}
	return (pos);
}

int	steps_to_top(t_stack stack, int pos)
{
	int	steps;

	if (pos <= stack.len / 2)
		steps = pos;
	else
		steps = stack.len - pos;
	return (steps);
}

t_cost	best_move(t_stack *a, t_stack *b)
{
	t_cost	check_price;
	t_cost	final_price;
	int		i;

	final_price.total_steps = INT_MAX;
	i = 0;
	while (i < b->len)
	{
		check_price.b_index = i;
		check_price.a_index = target_index(a, b->arr[i]);
		check_price.b_steps = steps_to_top(*b, i);
		check_price.a_steps = steps_to_top(*a, check_price.a_index);
		check_price.total_steps = check_price.a_steps + check_price.b_steps;
		if (final_price.total_steps > check_price.total_steps)
			final_price = check_price;
		i++;
	}
	return (final_price);
}
