/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:21:46 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:21:48 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)(haystack));
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] && i + (ft_strlen(needle) - 1) < len)
		{
			if (!(ft_strncmp(haystack + i, needle, ft_strlen(needle))))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
