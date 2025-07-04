/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:15 by gita              #+#    #+#             */
/*   Updated: 2025/07/04 18:44:49 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"


#include <stdio.h>
void	print_stack(t_stack stack_a, t_stack stack_b)
{
	int i = 0;
	printf("\nStack_a: ");
	while (i < stack_a.len)
	{
		printf("'%i'", stack_a.arr[i]);
		i++;
	}
	i = 0;
	printf("\nStack_b: ");
	while (i < stack_b.len)
	{
		printf("'%i'", stack_b.arr[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.arr = parse_args(ac, av);
	stack_a.len = ac - 1;
	stack_b.arr = malloc ((ac - 1) * sizeof(int));
	stack_b.len = 0;
	
	

	print_stack(stack_a, stack_b);
	p2b(&stack_a, &stack_b);
	p2b(&stack_a, &stack_b);
	p2b(&stack_a, &stack_b);
	p2b(&stack_a, &stack_b);
	ss(stack_a, stack_b);
	rr(stack_a, stack_b);
	rrr(stack_a, stack_b);
	print_stack(stack_a, stack_b);
}
