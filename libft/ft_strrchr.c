/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:09:52 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/17 18:30:07 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int length;

	length = ft_strlen(s);
	while (length > 0 && s[length] != c)
	{
		length--;
	}
	if (s[length] == c)
	{
		return ((char *)&(s[length]));
	}
	return (NULL);
}
