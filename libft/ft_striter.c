/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:58:42 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 19:24:06 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int length;
	int count;

	if (!s || !f)
		return ;
	count = 0;
	length = ft_strlen(s);
	while (count < length)
	{
		(*f)(&(s[count]));
		count++;
	}
}
