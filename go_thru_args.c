/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_thru_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:25:00 by gita              #+#    #+#             */
/*   Updated: 2025/06/29 20:36:18 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"
int	error_msg
{
	write(1, "Error\n", 6);
	return (2);
}

int	main(int ac, char **av)
{
	char	**splitted_arg;
	size_t	i;
	int		*arr;

	if (ac < 2)
		return (error_msg);
	if (ac == 2)
	{
		splitted_arg = ps_split(av[1], ' ');
		if (splitted_arg == NULL)
			return (error_msg);
		i = 0;
		while (splitted_arg[i])
			i++;
		if (i < 2)
			return (error_msg);
	}
	i = 1;
	while (*av[i])
	{
		if (!(*av[i] >= 0 && *av[i] <= 9) || *av[i] != ' '
			|| !(*av[i] >= 9 && *av[i] <= 13) || *av[i] != '+' || *av[i] != '-')
			return (error_msg);
		i++;
	}
	i = 0;
	arr = malloc((ac - 1) * sizeof(int));
	if (!arr)
		return (error_msg(2));
	while (arr[i])
	{
		arr[i] = ps_atoi(*av[i + 1]);
		if (arr[i] < INT_MIN || arr[i] > INT_MAX)
			return (error_msg);
		i++;
	}
}
