/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset3_bringtop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:16:11 by gita              #+#    #+#             */
/*   Updated: 2025/07/08 23:12:49 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	duo_roll(t_stack *stk_a, t_stack *stk_b, t_cost *best)
{
	if (best->a_index <= stk_a->len / 2 && best->b_index <= stk_b->len / 2)
	{
		while (best->a_steps > 0 && best->b_steps > 0)
		{
			rr(*stk_a, *stk_b);
			best->a_steps--;
			best->b_steps--;
			best->a_index--;
			best->b_index--;
		}
	}
	else if (best->a_index > stk_a->len / 2 && best->b_index > stk_b->len / 2)
	{
		while (best->a_steps > 0 && best->b_steps > 0)
		{
			rrr(*stk_a, *stk_b);
			best->a_steps--;
			best->b_steps--;
			best->a_index++;
			best->b_index++;
		}
	}
}

void	bring_to_top(int pos, int steps, t_stack *stack, int stk_code)
{
	if (pos <= stack->len / 2)
	{
		while (steps > 0)
		{
			if (stk_code == STACK_A)
				ra(*stack);
			else if (stk_code == STACK_B)
				rb(*stack);
			steps--;
		}
	}
	else
	{
		while (steps > 0)
		{
			if (stk_code == STACK_A)
				rra(*stack);
			else if (stk_code == STACK_B)
				rrb(*stack);
			steps--;
		}
	}
}
