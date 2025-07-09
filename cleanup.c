/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:36:30 by gita              #+#    #+#             */
/*   Updated: 2025/07/09 11:35:48 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	error_msg(void *freethis)
{
	if (freethis != NULL)
	{
		free(freethis);
		freethis = NULL;
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	free_data(t_stack stack_a, t_stack stack_b)
{
	if (stack_a.arr)
	{
		free(stack_a.arr);
		stack_a.arr = NULL;
	}
	if (stack_b.arr)
	{
		free(stack_b.arr);
		stack_b.arr = NULL;
	}
}
