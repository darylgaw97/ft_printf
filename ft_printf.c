/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:49:55 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 11:51:46 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse(const char *format, t_tab *tab, va_list *args, int *count);
static void	print(t_tab *tab, va_list *args, int *count);

int	ft_printf(const char *format, ...)
{
	t_tab	*tab;
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tab = initialise_tab();
			if (!tab)
				return (-1);
			format += parse(format, tab, &args, &count);
			free(tab);
			continue ;
		}
		count += write(1, format++, 1);
	}
	va_end(args);
	return (count);
}

/* this functions breaks down the various flags along with width and precision 
and assigns it to the struct t_tab, which will be used later on in the 
printing section.*/
static int	parse(const char *format, t_tab *tab, va_list *args, int *count)
{
	int	offset;

	offset = 1;
	while (ft_strchr("#0- +", format[offset]))
		offset += set_flags(tab, format[offset]);
	if (ft_isdigit(format[offset]))
		offset += set_width(tab, ft_atoi(format + offset));
	if (format[offset] == '.')
	{
		offset += set_precision(tab, ft_atoi(format + offset + 1));
		while (ft_isdigit(format[offset]))
			offset++;
	}
	if (!ft_strchr("cspdiuxX%", format[offset]))
		return (offset);
	offset += set_specifier(tab, format[offset]);
	handle_override(tab);
	print(tab, args, count);
	return (offset);
}

static void	print(t_tab *tab, va_list *args, int *count)
{
	if (tab->specifier == 'c')
		print_c(tab, args, count);
	else if (tab->specifier == 's')
		print_s(tab, args, count);
	else if (tab->specifier == 'p')
		print_p(tab, args, count);
	else if (tab->specifier == 'd' || tab->specifier == 'i')
		print_di(tab, args, count);
	else if (tab->specifier == 'u')
		print_u(tab, args, count);
	else if (tab->specifier == 'x' || tab->specifier == 'X')
		print_x(tab, args, count);
	else if (tab->specifier == '%')
		*count += write(1, "%", 1);
}
