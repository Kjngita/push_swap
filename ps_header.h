/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:40:03 by gita              #+#    #+#             */
/*   Updated: 2025/06/29 20:32:59 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HEADER_H
# define PS_HEADER_H

# include <stdlib.h>
# include <limits.h>

int	ps_atoi(const char *str);
char	**ps_split(char const *s, char sep);

#endif