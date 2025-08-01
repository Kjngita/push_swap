/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:15 by gita              #+#    #+#             */
/*   Updated: 2025/07/09 17:47:17 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.arr = parse_args(ac, av);
	stack_a.len = ac - 1;
	stack_b.arr = malloc ((ac - 1) * sizeof(int));
	stack_b.len = 0;
	if (!stack_a.arr || !stack_b.arr)
	{
		free_data(stack_a, stack_b);
		error_msg(NULL);
	}
	if (algo_worked(&stack_a, &stack_b) == 0)
	{
		free_data(stack_a, stack_b);
		error_msg(NULL);
	}
	free_data(stack_a, stack_b);
	return (0);
}
