/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 01:31:24 by lbricio-          #+#    #+#             */
/*   Updated: 2021/06/07 13:03:14 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\f' || c == '\v');
}

static int	l_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(const char *nptr)
{
    int num;
	int sign;

    while (l_isspace(*nptr))
        nptr++;
	sign = 1;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
	num = 0;
    while (l_isdigit(*nptr))
    {
        num *= 10;
        num += (*nptr - '0');
        nptr++;
    }
    return num * sign;
}
