/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:11:24 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:11:26 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;
	long unsigned	i;

	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
