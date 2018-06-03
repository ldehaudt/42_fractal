/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:37:22 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 12:48:25 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	recurse(char *str, int *count, int num, int first)
{
	int neg;

	neg = (num < 0) ? -1 : 1;
	if (num < 0 && first == 1)
	{
		str[0] = '-';
		(*count)++;
	}
	if (num >= 10 || num <= -10)
	{
		recurse(str, count, num / 10, 0);
	}
	str[*count] = neg * (num % 10) + '0';
	(*count)++;
}

static	int		int_length(int num, int first)
{
	int neg;

	neg = 0;
	if (num < 0 && first == 1)
	{
		num *= -1;
		neg = 1;
	}
	if (num >= 10 || num <= -10)
	{
		return (1 + neg + int_length(num / 10, 0));
	}
	return (1 + neg);
}

char			*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		num;

	num = 0;
	size = int_length(n, 1);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	recurse(str, &num, n, 1);
	return (str);
}
