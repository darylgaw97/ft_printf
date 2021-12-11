/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:15:01 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 12:15:56 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_tab	*initialise_tab(void)
{
	t_tab	*tab;

	tab = malloc(sizeof(t_tab));
	if (!tab)
		return (NULL);
	tab->hash = 0;
	tab->zero = 0;
	tab->minus = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->width = 0;
	tab->dot = 0;
	tab->precision = 0;
	tab->specifier = 0;
	tab->str_len = 0;
	tab->digit_len = 0;
	return (tab);
}

int	numlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
		n *= -1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	put_indent(t_tab *tab)
{
	tab->width--;
	if (tab->zero)
		return (ft_putchar('0'));
	return (ft_putchar(' '));
}
