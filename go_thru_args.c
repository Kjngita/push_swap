/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_thru_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:25:00 by gita              #+#    #+#             */
/*   Updated: 2025/07/09 17:56:35 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static long	ps_atol(const char *str)
{
	size_t	i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10 + str[i]) - '0';
		i++;
	}
	if (str[i] == 0 && (str[i - 1] == '+' || str[i - 1] == '-'))
		return (2147483648);
	else if (str[i] != 0)
		return (2147483648);
	return (num * sign);
}

static int	check_arg_value(int argc, char **argv, int *arr)
{
	int		i;
	long	num;
	int		p;

	i = 1;
	while (argv[i])
	{
		num = ps_atol(argv[i]);
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

static void	check_one_arg(char **av)
{
	long	value;

	value = ps_atol(av[1]);
	if (av[1][0] != 0 && (value >= INT_MIN && value <= INT_MAX))
		exit (1);
	else
		error_msg(NULL);
}

int	*parse_args(int ac, char **av)
{
	int	i;
	int	j;
	int	*chain;

	if (ac == 2)
		check_one_arg(av);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '+'
				|| av[i][j] == '-'))
				error_msg(NULL);
			j++;
		}
		i++;
	}
	chain = malloc ((ac - 1) * sizeof(int));
	if (!chain)
		return (NULL);
	if (check_arg_value(ac, av, chain) == 1)
		error_msg(chain);
	return (chain);
}
