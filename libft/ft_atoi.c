/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:55:22 by mpagani           #+#    #+#             */
/*   Updated: 2022/11/22 12:06:13 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_overflow(const char *str, int sign)
{
	long long int	res;
	int				i;

	res = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && res >= (LLONG_MAX / 10) && (str[i] - '0') > 7)
			return (-1);
		if (sign == -1 && res >= (LLONG_MAX / 10) && (str[i] - '0') > 8)
			return (0);
		res = (res * 10) + (str[i++] - '0');
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] == 9) || (str[i] == 10)
		|| (str[i] == 11) || (str[i] == 12) || (str[i] == 13))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	return ((int)ft_overflow((str + i), sign));
}
