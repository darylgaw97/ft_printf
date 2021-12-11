/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:19:53 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:19:54 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c);
static char	**no_substr(char **s);
static char	*make_substr(char const *s, char c, int *i);
static int	substrlen(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		str_count;
	int		i;

	if (s == NULL)
		return (NULL);
	str_count = count_strings(s, c);
	strings = malloc(sizeof(char *) * (str_count + 1));
	if (strings == NULL)
		return (NULL);
	if (str_count == 0)
		return (no_substr(strings));
	i = 0;
	str_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		strings[str_count] = make_substr((s + i), c, &i);
		str_count++;
	}
	strings[str_count] = NULL;
	return (strings);
}

static int	count_strings(char const *s, char c)
{
	int	i;
	int	str_count;

	i = 0;
	str_count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str_count++;
			while (s[i] && s[i] != c)
				i++;
			continue ;
		}
		i++;
	}
	return (str_count);
}

static char	**no_substr(char **s)
{
	s[0] = NULL;
	return (s);
}

static char	*make_substr(char const *s, char c, int *i)
{
	char	*substr;
	int		j;

	substr = malloc(substrlen(s, c) + 1);
	if (substr == NULL)
		return (NULL);
	j = 0;
	while (s[j] && s[j] != c)
	{
		substr[j] = s[j];
		j++;
	}
	substr[j] = '\0';
	*i += substrlen(s, c);
	return (substr);
}

static int	substrlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
