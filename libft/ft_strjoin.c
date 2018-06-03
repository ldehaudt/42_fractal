/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:05:31 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 17:53:33 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	length1;
	size_t	length2;
	size_t	count;

	count = 0;
	if (!s1 || !s2)
		return (NULL);
	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	str = (char *)ft_strnew(length1 + length2);
	if (!str)
	{
		return (NULL);
	}
	while (count < length1 + length2)
	{
		if (count < length1)
			str[count] = s1[count];
		else
			str[count] = s2[count - length1];
		count++;
	}
	return (str);
}
