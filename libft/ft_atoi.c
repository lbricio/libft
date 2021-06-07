/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 01:31:24 by lbricio-          #+#    #+#             */
/*   Updated: 2021/06/07 01:22:29 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long			result;
	long			sign;
	unsigned int	x;

	sign = 1;
	x = 0;
	while (str[x] == ' ' || str[x] == '\t' || str[x] == '\n'
		|| str[x] == '\r' || str[x] == '\v' || str[x] == '\f')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	result = 0;
	while (str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + str[x] - '0';
		x++;
	}
	return ((int)(result * sign));
}
