/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:52:01 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 11:53:03 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_flags(t_tab *tab, char c)
{
	if (c == '#')
		tab->hash = 2;
	else if (c == '0')
		tab->zero = 1;
	else if (c == '-')
		tab->minus = 1;
	else if (c == ' ')
		tab->space = 1;
	else if (c == '+')
		tab->plus = 1;
	return (1);
}

int	set_width(t_tab *tab, int n)
{
	tab->width = n;
	return (numlen(n));
}

int	set_precision(t_tab *tab, int n)
{
	tab->dot = 1;
	tab->precision = n;
	return (1);
}

int	set_specifier(t_tab *tab, char c)
{
	tab->specifier = c;
	return (1);
}

/*If the 0 and - flags both appear, the 0 flag is ignored. 
If a precision is given with a numeric conversion
(d, i, o, u, x, and X), the 0 flag is ignored.*/
void	handle_override(t_tab *tab)
{
	if (tab->minus || tab->precision)
		tab->zero = 0;
	if (tab->plus)
		tab->space = 0;
}
