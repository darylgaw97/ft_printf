/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:16:40 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:16:42 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ret;

	if (dest == NULL && src == NULL)
		return (NULL);
	ret = dest;
	i = 0;
	if (src < dest && (unsigned)(dest - src) < len)
	{
		i = len - 1;
		while (len--)
		{
			ret[i] = ((unsigned char *)src)[i];
			i--;
		}
		return (ret);
	}
	while (i < len)
	{
		ret[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (ret);
}
