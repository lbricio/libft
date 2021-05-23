/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:23:41 by lbricio-          #+#    #+#             */
/*   Updated: 2021/05/23 13:05:10 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t x;
	size_t y;

	if (n <= ft_strlen(dst))
		return (n + ft_strlen(src)); //dstsize + srclen
	x = ft_strlen(dst);
	y = 0;
	while ((src[y] != '\0') && (x + 1 < n))
	{
		dst[x] = src[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[y])); //dstlen + srclen[y]
}
