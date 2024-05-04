/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:30:32 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:13:22 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long int	result;
	long int	overunder_check;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	if (nptr[i] < '0' || nptr[i] > '9')
		exit (1);
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		overunder_check = result;
		result = (result * 10) + (nptr[i++] - '0');
		if (overunder_check > result && sign > 0)
			exit(1);
		else if (overunder_check > result && sign < 0)
			exit(1);
	}
	return ((int)(result * sign));
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	const char	*nptr = "21474836411111111111111111111111117";

	printf("%d\n", ft_atoi(nptr));
	printf("%d\n", atoi(nptr));
}*/
