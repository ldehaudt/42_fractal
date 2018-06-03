/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:35:48 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/20 13:49:59 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
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
		count++;
	}
	return (dst);
}
