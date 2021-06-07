/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:11:53 by lbricio-          #+#    #+#             */
/*   Updated: 2021/06/07 12:42:34 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;

	if (src == NULL || dest == NULL)
		return (0);
	if (size > 0)
	{
		x = 0;
		while (x < size - 1 && src[x])
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (ft_strlen(src));
}
