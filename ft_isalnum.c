/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 01:09:22 by lbricio-          #+#    #+#             */
/*   Updated: 2021/05/24 01:15:17 by lbricio-         ###   ########.fr       */
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

static int l_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool ft_isalnum(int c)
{
	return (l_isupper(c) || l_islower(c) || l_isdigit(c));
}
