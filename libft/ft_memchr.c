/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:16:15 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:16:17 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*memory;

	memory = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (memory[i] == (unsigned char)c)
			return ((void *)(memory + i));
		i++;
	}
	return (NULL);
}
