/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:11:58 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/18 13:19:56 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp1;

	if (!lst)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	tmp1 = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp1->next = f(lst)))
			return (NULL);
		tmp1 = tmp1->next;
		lst = lst->next;
	}
	return (new);
}
