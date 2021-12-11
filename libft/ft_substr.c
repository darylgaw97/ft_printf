/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:22:18 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:22:19 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if (slen - start > len)
		substr = malloc(sizeof(char) * len + 1);
	else
		substr = malloc(sizeof(char) * slen - start + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
