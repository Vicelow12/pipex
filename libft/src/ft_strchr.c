/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:52:51 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/27 16:16:25 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		*str_cpy;
	size_t		i;

	str_cpy = (char *)s;
	i = 0;
	while (str_cpy[i] != (char)c && str_cpy[i])
		i++;
	if (str_cpy[i] == (char)c)
		return (str_cpy + i);
	return (NULL);
}
