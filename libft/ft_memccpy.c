/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:02:33 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 08:59:00 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*ds;
	char		*sr;
	char		*pt;
	size_t		i;

	ds = (char *)dst;
	sr = (char *)src;
	pt = 0;
	i = 0;
	while (pt == 0 && i < n)
	{
		ds[i] = sr[i];
		if (sr[i] == (char)c)
			pt = ds + i + 1;
		i++;
	}
	return (pt);
}
