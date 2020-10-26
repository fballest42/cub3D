/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:03:00 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 08:59:13 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*ds;
	char		*sr;
	char		*dsf;
	char		*srf;

	ds = (char *)dst;
	sr = (char *)src;
	if ((n == 0) || (dst == src))
		return (dst);
	if (ds < sr)
	{
		while (n--)
			*ds++ = *sr++;
		return (dst);
	}
	dsf = ds + n - 1;
	srf = sr + n - 1;
	while (n--)
		*dsf-- = *srf--;
	return (dst);
}
