/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:37:08 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/27 16:24:06 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*str_cpy;
	size_t		i;

	str_cpy = (char *)s;
	i = ft_strlen(str_cpy);
	while (i != 0 && str_cpy[i] != (char)c)
		i--;
	if (str_cpy[i] == (char)c)
		return (str_cpy + i);
	return (NULL);
}
