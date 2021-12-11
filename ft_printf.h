/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:05:34 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:05:54 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef LIBFT_H
#  include "libft/libft.h"
# endif

# include <stdarg.h>

# define HEX "0123456789abcdef"

typedef struct s_tab
{
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		width;
	int		dot;
	int		precision;
	char	specifier;
	int		str_len;
	int		digit_len;
}	t_tab;

int		ft_printf(const char *str, ...);
void	print_c(t_tab *tab, va_list *args, int *count);
void	print_s(t_tab *tab, va_list *args, int *count);
void	print_p(t_tab *tab, va_list *args, int *count);
void	print_di(t_tab *tab, va_list *args, int *count);
void	print_u(t_tab *tab, va_list *args, int *count);
void	print_x(t_tab *tab, va_list *args, int *count);

/*parser*/
int		set_flags(t_tab *tab, char c);
int		set_width(t_tab *tab, int n);
int		set_precision(t_tab *tab, int n);
int		set_specifier(t_tab *tab, char c);
void	handle_override(t_tab *tab);

/*miscellaneous*/
t_tab	*initialise_tab(void);
int		numlen(long n);
int		put_indent(t_tab *tab);

#endif
