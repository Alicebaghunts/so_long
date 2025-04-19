/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:12:45 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/21 21:06:32 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!lst || !del || !f)
		return (NULL);
	new_list = ft_lstnew(f(lst -> content));
	if (!new_list)
		return (NULL);
	tmp = new_list;
	lst = lst -> next;
	while (lst != NULL)
	{
		new_list -> next = ft_lstnew(f(lst -> content));
		if (!new_list -> next)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		new_list = new_list -> next;
		lst = lst -> next;
	}
	return (tmp);
}
