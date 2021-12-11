/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:38:38 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:39:46 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numstrlen(unsigned int n);
static char	*make_a(char *a, unsigned int n);

char	*ft_uitoa(unsigned int n)
{
	char	*a;

	a = malloc(numstrlen(n) + 1);
	if (a == NULL)
		return (NULL);
	return (make_a(a, n));
}

static char	*make_a(char *a, unsigned int n)
{
	int	i;

	i = 0;
	i = numstrlen(n);
	a[i] = '\0';
	i--;
	if (n == 0)
		a[i] = '0';
	while (n != 0)
	{
		a[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (a);
}

static int	numstrlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
