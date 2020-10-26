/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:33:59 by fballest          #+#    #+#             */
/*   Updated: 2020/10/08 15:06:55 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;
	size_t		i;
	size_t		j;

	j = 0;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
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
