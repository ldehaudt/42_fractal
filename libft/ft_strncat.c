/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:30:31 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/20 12:51:08 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int		index;
	size_t	count;

	count = 0;
	index = ft_strlen(s1);
	while (s2[count] && count < n)
	{
		s1[index] = s2[count];
		index++;
		count++;
	}
	s1[index] = '\0';
	return (s1);
}
