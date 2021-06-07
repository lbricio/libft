/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:58:02 by lbricio-          #+#    #+#             */
/*   Updated: 2021/05/30 15:34:04 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		x;
	int		y;

	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(s1) || !(s2) || !(new_str))
		return (0);
	x = 0;
	while (s1[x] != '\0')
	{
		new_str[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y] != '\0')
	{
		new_str[x] = s2[y];
		x++;
		y++;
	}
	new_str[x] = '\0';
	return (new_str);
}
