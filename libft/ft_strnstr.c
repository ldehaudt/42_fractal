/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:28:00 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/18 13:20:38 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t cur;
	size_t cnt;

	cnt = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (cnt < len && *haystack)
	{
		cur = 0;
		while (cnt + cur < len && needle[cur] == haystack[cur])
		{
			if (!needle[cur + 1])
			{
				return ((char *)haystack);
			}
			cur++;
		}
		cnt++;
		haystack++;
	}
	return (NULL);
}
