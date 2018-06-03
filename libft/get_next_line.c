/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 00:24:28 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/13 22:27:24 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_increase(char **str)
{
	char *new;

	if (*str == NULL)
	{
		new = ft_strnew(BUFF_SIZE);
		return (new);
	}
	new = ft_strnew(ft_strlen(*str) + BUFF_SIZE);
	new = ft_strcpy(new, *str);
	free(*str);
	return (new);
}

int		contains_nl(char *str)
{
	int count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

char	*cut_str(char **line, char **src, int cutoff)
{
	char	*rem;
	int		size;

	size = ft_strlen(*src);
	*line = ft_strnew(cutoff + 1);
	*line = ft_strncpy(*line, *src, cutoff);
	rem = malloc(size - cutoff);
	rem = ft_strcpy(rem, &(src[0][cutoff + 1]));
	free(*src);
	return (rem);
}

int		get_next_line(const int fd, char **line)
{
	static char	**remainder;
	int			nl_found;
	int			size;
	int			ret;

	if (!remainder)
		remainder = malloc(sizeof(char *) * 5000);
	ret = -1;
	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	while ((nl_found = contains_nl(remainder[fd])) == -1 && ret == -1)
	{
		size = ft_strlen(remainder[fd]);
		remainder[fd] = str_increase(&(remainder[fd]));
		if (read(fd, &(remainder[fd][size]), BUFF_SIZE) == 0)
			ret = (size == 0) ? 0 : 1;
	}
	if (ret != -1)
	{
		remainder[fd] = cut_str(line, &(remainder[fd]),
		ft_strlen(remainder[fd]));
		return (ret);
	}
	remainder[fd] = cut_str(line, &(remainder[fd]), nl_found);
	return (1);
}
