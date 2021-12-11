/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:54:39 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:36:43 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ul_to_hex(unsigned long p);

void	print_p(t_tab *tab, va_list *args, int *count)
{
	unsigned long	p;
	char			*str;

	p = va_arg(*args, unsigned long);
	str = ul_to_hex(p);
	tab->str_len = ft_strlen(str);
	if (tab->minus == 0)
	{
		while (tab->width-- > tab->str_len + 2)
			*count += write(1, " ", 1);
	}
	*count += ft_putstr("0x");
	tab->width -= 2;
	*count += ft_putstr(str);
	free(str);
	tab->width -= tab->str_len;
	while (tab->width-- > 0)
		*count += write(1, " ", 1);
}

static char	*ul_to_hex(unsigned long p)
{
	char	reversed[17];
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (p / 16)
	{
		reversed[i++] = HEX[p % 16];
		p /= 16;
	}
	reversed[i++] = HEX[p];
	reversed[i] = '\0';
	str = malloc(sizeof(char) * i + 1);
	i--;
	j = 0;
	while (reversed + i != reversed - 1)
		str[j++] = reversed[i--];
	str[j] = '\0';
	return (str);
}
