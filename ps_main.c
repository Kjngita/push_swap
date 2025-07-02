/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:15 by gita              #+#    #+#             */
/*   Updated: 2025/07/03 01:17:58 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	int	*stack_a;
	// int	*stack_b;

	stack_a = parse_args(ac, av);
	int i = 0;
	while (i++ < ac - 2)
		printf("Stack_a '%i'\n", stack_a[i]);
}