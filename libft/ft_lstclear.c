/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaw <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:14:38 by dgaw              #+#    #+#             */
/*   Updated: 2021/12/11 14:14:39 by dgaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		n = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(n, del);
	}
}
