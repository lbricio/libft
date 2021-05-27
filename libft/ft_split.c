/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:48:40 by lbricio-          #+#    #+#             */
/*   Updated: 2021/05/27 15:05:18 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_wordcount(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	if (!s || !c)
		return (0);
	while (*s)
	{
		if (*s == c && flag == 1)
			flag = 0;
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int	ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		nb_words;
	char	**rtn;

	i = 0;
	nb_words = ft_wordcount((const char *)s, c);
	rtn = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (rtn == NULL)
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		rtn[i] = ft_strsub((const char *)s, 0, ft_wordlen((const char *)s, c));
		s = s + ft_wordlen((const char *)s, c);
		i++;
	}
	rtn[i] = NULL;
	return (rtn);
}
