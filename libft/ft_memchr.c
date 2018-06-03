/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:06:55 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 17:08:25 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	char	*p;

	p = (char *)s;
	count = 0;
	while (count < n)
	{
		if ((unsigned char)p[count] == (unsigned char)c)
		{
			return (&(p[count]));
		}
		count++;
	}
	return (NULL);
}
