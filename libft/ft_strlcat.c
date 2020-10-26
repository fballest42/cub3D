/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:20:09 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 08:59:53 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t ds)
{
	size_t		sc;
	size_t		i;
	size_t		j;

	sc = 0;
	while (src[sc] != '\0')
		sc++;
	i = 0;
	while (dst[i] && i < ds)
		i++;
	j = 0;
	while (src[j] && i + j + 1 < ds)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != ds)
		dst[i + j] = '\0';
	return (i + sc);
}
