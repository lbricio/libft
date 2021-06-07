/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:16:49 by lbricio-          #+#    #+#             */
/*   Updated: 2021/05/24 23:20:14 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	original_size;
	char	*new_string;

	original_size = ft_strlen(s) + 1;
	new_string = malloc((original_size) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_memcpy(new_string, s, original_size);
	return (new_string);
}
