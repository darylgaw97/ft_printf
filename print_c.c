/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:53:40 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 12:21:09 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_tab *tab, va_list *args, int *count)
{
	int	c;

	c = va_arg(*args, int);
	if (tab->minus == 0)
	{
		while (tab->width-- > 1)
			*count += write(1, " ", 1);
	}
	*count += ft_putchar(c);
	while (tab->width-- > 1)
		*count += write (1, " ", 1);
}
