/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:19:38 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/20 11:52:52 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p;
	const char	*p2;

	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		p = dst;
		p2 = src;
		while (len)
		{
			len--;
			p[len] = p2[len];
		}
	}
	return (dst);
}
