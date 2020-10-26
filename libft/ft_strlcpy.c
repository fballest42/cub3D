/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:27:06 by fballest          #+#    #+#             */
/*   Updated: 2020/10/08 15:06:00 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t cn)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (src[i] != '\0')
		i++;
	if (cn == 0)
		return (i);
	while (*src && cn > 1)
	{
		*dst++ = *src++;
		cn--;
	}
	*dst = '\0';
	return (i);
}
