/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:28:15 by lbricio-          #+#    #+#             */
/*   Updated: 2021/06/04 19:36:45 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
    unsigned char *d;
    const unsigned char *s;

	d = dst;
	s = src;
    if (d == s)
        return d;
    if (d < s) 
	{
        i = 0;
        while (i < len)
            d[i] = s[i];
                i++;
    }
	else
	{
        i = len;
        while (i > 0)
            d[i-1] = s[i-1];
                i--;
    }
    return dst;
}
