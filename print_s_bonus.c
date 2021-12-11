/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:16:31 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 12:16:39 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_s(t_tab *tab, va_list *args, int *count)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	tab->str_len = ft_strlen(str);
	if (tab->precision < tab->str_len && tab->dot)
		tab->str_len = tab->precision;
	if (tab->minus == 0)
	{
		while (tab->width-- > tab->str_len)
			*count += write(1, " ", 1);
	}
	while (tab->str_len-- && *str)
	{
		*count += ft_putchar(*(str++));
		tab->width--;
	}
	while (tab->width-- > 0)
		*count += write(1, " ", 1);
}
