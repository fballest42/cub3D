/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:26:19 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 09:00:02 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		if (!(str = ft_strdup((char const *)s)))
			return (NULL);
		while (str[i] != 0)
		{
			str[i] = f(i, str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
