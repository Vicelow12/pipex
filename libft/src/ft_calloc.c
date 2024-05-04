/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:10:31 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/28 15:08:57 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
	{
		mem = malloc(0);
		if (!mem)
			return (NULL);
		else
			return (mem);
	}
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	if (mem)
		ft_bzero(mem, nmemb * size);
	return (mem);
}
