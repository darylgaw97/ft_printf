/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:22:00 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:22:02 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s1, char const *set);
static int	find_end(char const *s1, char const *set);
static int	in_set(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = find_start(s1, set);
	j = find_end(s1, set);
	if (i <= j)
	{
		trim = malloc(j - i + 2);
		if (trim == NULL)
			return (NULL);
		k = 0;
		while (i <= j)
			trim[k++] = s1[i++];
		trim[k] = '\0';
		return (trim);
	}
	trim = malloc(1);
	trim[0] = '\0';
	return (trim);
}

static int	find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (in_set(s1[i], set))
		i++;
	return (i);
}

static int	find_end(char const *s1, char const *set)
{
	int	j;

	j = 0;
	while (s1[j])
		j++;
	j--;
	while (in_set(s1[j], set) && s1 + j > s1)
		j--;
	return (j);
}

static int	in_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
