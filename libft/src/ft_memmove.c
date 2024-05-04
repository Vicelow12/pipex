/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:55:48 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/10 14:54:45 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
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
