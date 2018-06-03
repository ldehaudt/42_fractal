/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:49:55 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 13:01:44 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	size_t		count;
	char		*p;
	const char	*p2;

	p = dst;
	p2 = src;
	count = 0;
	while (count < n)
	{
		p[count] = p2[count];
		if ((unsigned char)p2[count] == (unsigned char)c)
		{
			return (&(dst[count + 1]));
		}
		count++;
	}
	return (NULL);
}
