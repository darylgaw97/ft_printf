/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:56:43 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 11:58:18 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_di_right(t_tab *tab, char *str, int di, int *count);
static void	print_di_left(t_tab *tab, char *str, int di, int *count);
static int	put_sign(t_tab *tab, int di);

void	print_di(t_tab *tab, va_list *args, int *count)
{
	int		di;
	char	*str;

	di = va_arg(*args, int);
	tab->str_len = numlen(di);
	str = ft_itoa(di);
	if (tab->dot && tab->precision == 0 && di == 0)
	{
		free(str);
		str = ft_strdup("");
		tab->str_len = 0;
	}
	if (tab->precision > tab->str_len)
		tab->digit_len = tab->precision;
	else
		tab->digit_len = tab->str_len;
	if (di < 0)
		tab->plus = 1;
	handle_override(tab);
	if (tab->minus == 0)
		print_di_right(tab, str, di, count);
	else
		print_di_left(tab, str, di, count);
	free(str);
}

static void	print_di_left(t_tab *tab, char *str, int di, int *count)
{
	*count += put_sign(tab, di);
	while (tab->precision-- > tab->str_len)
	{
		*count += ft_putchar('0');
		tab->width--;
	}
	if (di < 0)
		str++;
	*count += ft_putstr(str);
	tab->width -= ft_strlen(str);
	while (tab->width-- > 0)
		*count += ft_putchar(' ');
}

static void	print_di_right(t_tab *tab, char *str, int di, int *count)
{
	if (tab->zero)
		*count += put_sign(tab, di);
	while (tab->width > tab->digit_len + tab->plus + tab->space)
		*count += put_indent(tab);
	*count += put_sign(tab, di);
	while (tab->precision-- > tab->str_len)
		*count += ft_putchar('0');
	if (di < 0)
		str++;
	*count += ft_putstr(str);
}

static int	put_sign(t_tab *tab, int di)
{
	if (!tab->plus && !tab->space)
		return (0);
	if (tab->plus)
	{
		if (di < 0)
			ft_putchar('-');
		else
			ft_putchar('+');
	}
	if (tab->space)
		ft_putchar(' ');
	tab->width--;
	tab->plus = 0;
	tab->space = 0;
	return (1);
}
