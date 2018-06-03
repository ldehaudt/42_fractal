/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:24:15 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 12:41:39 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int index;
	int count;

	count = 0;
	index = ft_strlen(s1);
	while (s2[count])
	{
		s1[index] = s2[count];
		index++;
		count++;
	}
	s1[index] = '\0';
	return (s1);
}
