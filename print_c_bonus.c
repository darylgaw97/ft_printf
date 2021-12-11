/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:16:09 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 12:16:17 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
