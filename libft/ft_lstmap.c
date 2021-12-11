/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:15:05 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:15:07 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		n = ft_lstnew((*f)(lst->content));
		if (n == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, n);
		lst = lst->next;
	}
	return (new);
}
