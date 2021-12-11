/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:18:47 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 12:19:15 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_u_right(t_tab *tab, char *str, int *count);
static void	print_u_left(t_tab *tab, char *str, int *count);

void	print_u(t_tab *tab, va_list *args, int *count)
{
	unsigned int	u;
	char			*str;

	u = va_arg(*args, unsigned int);
	str = ft_uitoa(u);
	tab->str_len = ft_strlen(str);
	if (tab->dot && tab->precision == 0 && u == 0)
	{
		free(str);
		str = ft_strdup("");
		tab->str_len = 0;
	}
	if (tab->minus == 0)
		print_u_right(tab, str, count);
	else
		print_u_left(tab, str, count);
	free(str);
}

static void	print_u_right(t_tab *tab, char *str, int *count)
{
	while (tab->width > tab->precision && tab->width > tab->str_len)
		*count += put_indent(tab);
	while (tab->precision-- > tab->str_len)
		*count += ft_putchar('0');
	*count += ft_putstr(str);
}

static void	print_u_left(t_tab *tab, char *str, int *count)
{
	while (tab->precision-- > tab->str_len)
	{
		*count += ft_putchar('0');
		tab->width--;
	}
	*count += ft_putstr(str);
	tab->width -= tab->str_len;
	while (tab->width-- > 0)
		*count += ft_putchar(' ');
}
