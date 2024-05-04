/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:52:59 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/22 14:40:09 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	if (s1[i] != s2[i])
		return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
	return (0);
}
