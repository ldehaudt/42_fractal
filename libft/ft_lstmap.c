/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:32:59 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 18:47:07 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *new;
	t_list *tmp;

	ret = NULL;
	new = NULL;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (!tmp)
			return (NULL);
		if (new)
			(new)->next = tmp;
		new = tmp;
		if (!ret)
			ret = new;
		lst = (lst)->next;
	}
	return (ret);
}
