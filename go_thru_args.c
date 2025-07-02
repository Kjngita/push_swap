/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_thru_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:25:00 by gita              #+#    #+#             */
/*   Updated: 2025/07/03 01:15:52 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	error_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static int	check_args(int argc, char **argv, int *arr)
{
	int		i;
	long	num;
	int		p;

	i = 1;
	while (argv[i])
	{
		num = ps_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (1);
		arr[i - 1] = num;
		i++;
	}
	i = 0;
	while (i <= argc - 3)
	{
		p = i + 1;
		while (p <= argc - 2)
		{
			if (arr[i] == arr[p++])
				return (1);
		}
		i++;
	}
	return (0);
}

int	*parse_args(int ac, char **av)
{
	int	i;
	int j;
	int	*chain;
	
	if (ac == 2)
		error_msg();
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '+' || av[i][j] == '-'))
				error_msg();
			j++;
		}
		i++;
	}
	chain = malloc ((ac - 1) * sizeof(int));
	if (!chain)
		error_msg();
	if (check_args(ac, av, chain) == 1)
		error_msg();
	return (chain);
}
