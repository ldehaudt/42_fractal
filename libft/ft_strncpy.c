/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:00:36 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 13:50:46 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t count;
	size_t l;

	l = ft_strlen(src);
	count = 0;
	while (count < len)
	{
		if (count < l)
		{
			dst[count] = src[count];
		}
		else
		{
			dst[count] = '\0';
		}
		count++;
	}
	return (dst);
}
