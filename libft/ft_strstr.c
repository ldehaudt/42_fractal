/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:25:42 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/16 22:15:29 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int cur;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		cur = 0;
		while (needle[cur] == haystack[cur])
		{
			if (!needle[cur + 1])
			{
				return ((char *)haystack);
			}
			cur++;
		}
		haystack++;
	}
	return (NULL);
}
