/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:03:26 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 17:58:49 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int length;
	int count;

	if (!s || !f)
		return ;
	count = 0;
	length = ft_strlen(s);
	while (count < length)
	{
		(*f)(count, &(s[count]));
		count++;
	}
}
