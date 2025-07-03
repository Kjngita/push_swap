/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:15 by gita              #+#    #+#             */
/*   Updated: 2025/07/03 23:05:06 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.arr = parse_args(ac, av);
	stack_a.len = ac - 1;
	stack_b.arr = malloc ((ac - 1) * sizeof(int));
	stack_b.len = 0;
	
	

	int i = 0;
	printf("Stack_a: ");
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
	// rra(stack_a);
	p2b(stack_a, stack_b);
	i = 0;
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
