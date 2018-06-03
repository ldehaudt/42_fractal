/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:27:02 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 17:49:53 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	start = 0;
	while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n'))
	{
		start++;
	}
	end = ft_strlen(s) - 1;
	if (start > end)
	{
		return (ft_strsub(s, 0, 0));
	}
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
	{
		end--;
	}
	str = ft_strsub(s, start, end - start + 1);
	if (str)
		return (str);
	return (NULL);
}
