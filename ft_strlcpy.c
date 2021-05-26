/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:11:53 by lbricio-          #+#    #+#             */
/*   Updated: 2021/05/23 02:01:10 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	maxlen;
	size_t	x;

	if (!dst || !src)
		return (0);
	maxlen = ft_strlen(src);
	x = 0;
	while (src[x] != '\0' && x < (maxlen - 1))
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (maxlen);
}
