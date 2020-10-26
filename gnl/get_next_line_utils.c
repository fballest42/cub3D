/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:12:49 by fballest          #+#    #+#             */
/*   Updated: 2020/10/08 15:04:54 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlenc(const char *str)
{
	size_t		a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char		*ft_strdupc(const char *s1)
{
	size_t		ln;
	size_t		i;
	char		*str;

	ln = 0;
	i = 0;
	while (s1[ln] != '\0')
		ln++;
	str = (char*)malloc(ln + 1);
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strjoinc(char const *s1, char const *s2)
{
	char		*dst;
	size_t		i;
	size_t		j;

	j = 0;
	if (!s1 || !s2)
		return (0);
	i = ft_strlenc(s1) + ft_strlenc(s2) + 1;
	if (!(dst = (char *)malloc(sizeof(char) * i)))
		return (0);
	while (s1[j] != '\0')
	{
		dst[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dst[j] = s2[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

char		*ft_strchrc(const char *s, int c)
{
	char			*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

char		*ft_substrc(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*dst;
	size_t			size;

	i = 0;
	if (!s)
		return (0);
	i = ft_strlenc(s);
	if (i < start)
		return (ft_strdupc(""));
	size = ft_strlenc(s + start);
	if (size < len)
		len = size;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
