/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:36:50 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 09:00:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (*src == '\0')
		return ((char *)dst);
	while (dst[i] && i < len)
	{
		if (dst[i] == src[0])
		{
			j = 0;
			while (src[j] && src[j] == dst[i + j] && (i + j) < len)
			{
				j++;
				if (src[j] == '\0')
					return ((char *)dst + i);
			}
		}
		i++;
	}
	return (0);
}
