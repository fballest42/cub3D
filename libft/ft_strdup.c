/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:11:05 by fballest          #+#    #+#             */
/*   Updated: 2020/10/08 15:05:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *s1)
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
