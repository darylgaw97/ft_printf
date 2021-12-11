/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:59:29 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:05:11 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ui_to_hex(unsigned int x);
static void	print_x_right(t_tab *tab, char *str, int *count, unsigned int x);
static void	print_x_left(t_tab *tab, char *str, int *count, unsigned int x);
static int	put_prefix(t_tab *tab, unsigned int x);

void	print_x(t_tab *tab, va_list *args, int *count)
{
	unsigned int	x;
	char			*str;

	x = va_arg(*args, unsigned int);
	str = ui_to_hex(x);
	tab->str_len = ft_strlen(str);
	if (x == 0 && tab->dot && tab->precision == 0)
	{
		free(str);
		str = ft_strdup("");
		tab->str_len = 0;
	}
	tab->digit_len = tab->str_len;
	if (tab->precision > tab->str_len)
		tab->digit_len = tab->precision;
	if (tab->minus == 0)
		print_x_right(tab, str, count, x);
	else
		print_x_left(tab, str, count, x);
	free(str);
}

static void	print_x_right(t_tab *tab, char *str, int *count, unsigned int x)
{
	int	i;

	if (tab->zero)
		*count += put_prefix(tab, x);
	while (tab->width > tab->digit_len + tab->hash)
		*count += put_indent(tab);
	*count += put_prefix(tab, x);
	while (tab->precision-- > tab->str_len)
		*count += ft_putchar('0');
	if (tab->specifier == 'X')
	{
		i = 0;
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	*count += ft_putstr(str);
}

static void	print_x_left(t_tab *tab, char *str, int *count, unsigned int x)
{
	int	i;

	*count += put_prefix(tab, x);
	while (tab->precision-- > tab->str_len)
	{
		*count += ft_putchar('0');
		tab->width--;
	}
	if (tab->specifier == 'X')
	{
		i = 0;
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	*count += ft_putstr(str);
	tab->width -= tab->str_len;
	while (tab->width-- > 0)
		*count += ft_putchar(' ');
}

static int	put_prefix(t_tab *tab, unsigned int x)
{
	if (!tab->hash || !x)
		return (0);
	if (tab->specifier == 'x')
		ft_putstr("0x");
	else if (tab->specifier == 'X')
		ft_putstr("0X");
	tab->width -= 2;
	tab->hash = 0;
	return (2);
}

static char	*ui_to_hex(unsigned int x)
{
	char	reversed[9];
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (x / 16)
	{
		reversed[i++] = HEX[x % 16];
		x /= 16;
	}
	reversed[i++] = HEX[x];
	reversed[i] = '\0';
	str = malloc(sizeof(char) * i + 1);
	i--;
	j = 0;
	while (reversed + i != reversed - 1)
		str[j++] = reversed[i--];
	str[j] = '\0';
	return (str);
}
