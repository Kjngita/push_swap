/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:40:03 by gita              #+#    #+#             */
/*   Updated: 2025/07/04 18:17:57 by gita             ###   ########.fr       */
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

void	error_msg(void);
long	ps_atoi(const char *str);
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


#endif