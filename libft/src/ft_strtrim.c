/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:40:51 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/27 17:14:12 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	trim_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	if (j == ft_strlen(s1))
		return (0);
	return (j);
}

static	size_t	trim_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count_end;

	j = ft_strlen(s1) - 1;
	i = 0;
	count_end = 0;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			j--;
			count_end++;
			i = 0;
		}
		else
			i++;
	}
	return (count_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*cpy;
	size_t		i;
	size_t		j;

	cpy = malloc(sizeof(char) * (ft_strlen(s1) - trim_start(s1, set)
				- trim_end(s1, set) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	j = trim_start(s1, set);
	while (j < ft_strlen(s1) - trim_end(s1, set))
	{
		cpy[i] = s1[j];
		i++;
		j++;
	}
	cpy[i] = '\0';
	return (cpy);
}
