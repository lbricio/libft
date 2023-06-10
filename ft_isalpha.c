/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 01:07:14 by lbricio-          #+#    #+#             */
/*   Updated: 2021/05/24 01:19:37 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int l_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int l_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

bool ft_isalpha(int c)
{
	return (l_isupper(c) && l_islower(c));
}
