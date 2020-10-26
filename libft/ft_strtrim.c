/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:44:26 by fballest          #+#    #+#             */
/*   Updated: 2020/10/08 15:09:21 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*fin;
	size_t		in;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	in = ft_strlen(s1);
	while (in && ft_strchr(set, s1[in]))
		in--;
	fin = ft_substr(s1, 0, in + 1);
	return (fin);
}
