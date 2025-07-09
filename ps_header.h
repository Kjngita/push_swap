/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:40:03 by gita              #+#    #+#             */
/*   Updated: 2025/07/09 16:07:54 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HEADER_H
# define PS_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*arr;
	int	len;
}	t_stack;

typedef struct s_cost
{
	int	b_index;
	int	a_index;
	int	b_steps;
	int	a_steps;
	int	total_steps;
}	t_cost;

enum	stk_code
{
	STACK_A,
	STACK_B
};

int		*parse_args(int ac, char **av);

void	sa(t_stack stack_a);
void	sb(t_stack stack_b);
void	ss(t_stack stack_a, t_stack stack_b);
void	p2a(t_stack *stack_a, t_stack *stack_b);
void	p2b(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack stack_a);
void	rb(t_stack stack_b);
void	rr(t_stack stack_a, t_stack stack_b);
void	rra(t_stack stack_a);
void	rrb(t_stack stack_b);
void	rrr(t_stack stack_a, t_stack stack_b);

int		algo_worked(t_stack *a, t_stack *b);
t_cost	best_move(t_stack *a, t_stack *b);
int		min_value_pos(t_stack stack);
int		steps_to_top(t_stack stack, int pos);
void	duo_roll(t_stack *stk_a, t_stack *stk_b, t_cost *best);
void	bring_to_top(int pos, int steps, t_stack *stack, int stk_code);

void	error_msg(void *freethis);
void	free_data(t_stack stack_a, t_stack stack_b);

#endif