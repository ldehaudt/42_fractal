/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:08:40 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 17:59:24 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		length;
	int		count;
	char	*str;

	count = 0;
	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	while (count < length)
	{
		str[count] = (*f)(s[count]);
		count++;
	}
	return (str);
}
