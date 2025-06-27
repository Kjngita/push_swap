/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_thru_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:25:00 by gita              #+#    #+#             */
/*   Updated: 2025/06/27 22:30:07 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"
int	error_msg(int err)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int ac, char **av)
{
	size_t	i;
	int		arr;
	size_t	a;
	size_t	b;

	if (ac < 3)
		return (0);
	i = 1;
	while (*av[i])
	{
		if (!(*av[i] >= 0 && *av[i] <= 9) || *av[i] != ' '
			|| !(*av[i] >= 9 && *av[i] <= 13) || *av[i] != '+' || *av[i] != '-')
			return (error_msg(2));
		i++;
	}
	i = 1;
	a = 0;
	arr = malloc ((ac - 1) * sizeof(int));
	if (!arr)
		return (error_msg(2));
	while (*av[i])
	{
		arr[a++] = ps_atoi(*av[i++]);
		if (arr[a] < INT_MIN || arr[a] > INT_MAX)
			return (error_msg(2));
	}
	a = 0;
	while (arr[a])
	{
		b = a; 
		while (b < ac - 1)
		{
			if arr[a] == arr[b]
				return (error_msg(2))
			b++;
		}
		a++;
	}
}
