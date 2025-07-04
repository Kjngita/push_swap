/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:36:30 by gita              #+#    #+#             */
/*   Updated: 2025/07/04 20:56:31 by gita             ###   ########.fr       */
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
	write(1, "Error\n", 6);
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