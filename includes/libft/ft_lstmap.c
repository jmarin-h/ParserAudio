/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:53:28 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/12/01 04:21:00 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	res = f(lst);
	lst = lst->next;
	tmp = res;
	while (lst != NULL)
	{
		tmp->next = f(lst);
		if (!(tmp->next))
			return (NULL);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (res);
}
