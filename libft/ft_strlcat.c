/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:54:58 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 12:31:04 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t length;
	size_t length_src;
	size_t count;

	length_src = ft_strlen(src);
	length = ft_strlen(dst);
	count = 0;
	if (size < length)
		return (size + length_src);
	while (count + length + 1 < size && src[count])
	{
		dst[length + count] = src[count];
		count++;
	}
	dst[length + count] = '\0';
	return (length + length_src);
}
