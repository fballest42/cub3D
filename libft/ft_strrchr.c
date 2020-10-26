/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:16:48 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 09:00:11 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;

	ch = NULL;
	if (*s == c)
		return ((char *)s);
	while (*s++)
	{
		if (*s == c)
			ch = (char *)s;
	}
	if (ch)
		return (ch);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
