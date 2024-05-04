/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:34:07 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/04/30 17:48:49 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strl(char *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	return (i);
}

size_t	check_n(char *src)
{
	size_t	i;
	size_t	ncount;

	i = 0;
	ncount = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			ncount++;
		i++;
	}
	return (ncount);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (buf[0] == '\0')
		line = readline(line, buf, check_n(buf), fd);
	else
	{
		line = ft_strjoin(line, ft_strdup(buf));
		if (!line)
			return (NULL);
		if (check_n(buf) == 0)
			line = readline(line, buf, check_n(buf), fd);
		else if (buf[0] != '\0' )
			ft_memmove(buf, buf + strl(buf), BUFFER_SIZE - strl(buf) + 1);
	}
	if (!line)
		return (buf[0] = '\0', NULL);
	return (line);
}
