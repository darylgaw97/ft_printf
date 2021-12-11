/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:16:24 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:16:26 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*memory1;
	unsigned char	*memory2;

	memory1 = (unsigned char *)s1;
	memory2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (memory1[i] != memory2[i])
			return (memory1[i] - memory2[i]);
		i++;
	}
	return (0);
}
