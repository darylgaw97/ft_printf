/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:09:03 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:09:19 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c);

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result = result + nptr[i] - '0';
		i++;
	}
	if (sign == -1)
		result *= sign;
	return (result);
}

static int	ft_isspace(const char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
