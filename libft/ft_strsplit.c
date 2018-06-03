/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:13:17 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/04/19 18:45:37 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		word_count(const char *s, char c)
{
	int wc;
	int count;

	count = 0;
	wc = 0;
	while (s[count])
	{
		if (s[count] != c && (count == 0 || s[count - 1] == c))
		{
			wc++;
		}
		count++;
	}
	return (wc);
}

static	char	*check(const char *s, int *cur, int *start, int count)
{
	char *temp;

	temp = ft_strsub(s, *start, count - *start);
	(*cur)++;
	*start = -1;
	return (temp);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**str;
	int		count;
	int		start;
	int		cur;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	count = -1;
	start = -1;
	cur = -1;
	while (s[++count])
		if (s[count] == c)
			str[cur] = (start != -1) ? check(s, &cur, &start, count) : str[cur];
		else if (count == 0 || s[count - 1] == c)
			start = count;
	if (start != -1)
		str[cur] = check(s, &cur, &start, count);
	str[cur + 1] = NULL;
	return (str);
}
