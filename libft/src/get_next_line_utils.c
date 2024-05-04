/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:18:46 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/02 20:16:06 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;

	i = -1;
	j = 0;
	if ((!s1) || (!s2))
		return (free(s1), free(s2), NULL);
	s1len = strl(s1);
	s2len = strl(s2);
	join = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!join)
		return (free(s1), free(s2), NULL);
	while (++i < s1len)
		join[i] = s1[i];
	while (i < s1len + s2len)
		join[i++] = s2[j++];
	join[i] = '\0';
	return (free(s1), free(s2), join);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (strl (s) + 1));
	if (!new)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*cpy_dest;
	char	*cpy_src;

	if (!(dest || src))
		return (NULL);
	i = 0;
	cpy_dest = (char *)dest;
	cpy_src = (char *)src;
	while (i < n)
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*cpy_dest;
	char	*cpy_src;

	i = 0;
	cpy_dest = (char *)dest;
	cpy_src = (char *)src;
	if (cpy_src == cpy_dest || n == 0)
		return (dest);
	if (cpy_dest > cpy_src && cpy_dest - cpy_src < (int)n)
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			cpy_dest[i] = cpy_src[i];
			i--;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

char	*readline(char *line, char *buf, size_t n, int fd)
{
	ssize_t	bytesread;

	while (n == 0)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			if (bytesread == 0 && line[0] != '\0')
				break ;
			else
			{
				free(line);
				return (NULL);
			}
		}
		buf[bytesread] = '\0';
		n = check_n(buf);
		line = ft_strjoin(line, ft_strdup(buf));
		if (!line)
			return (NULL);
	}
	if (buf[0] != '\0')
		ft_memmove(buf, buf + strl(buf), BUFFER_SIZE - strl(buf) + 1);
	return (line);
}
