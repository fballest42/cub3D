/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:16:51 by fballest          #+#    #+#             */
/*   Updated: 2021/01/23 09:46:53 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char		*c;
	size_t		i;

	c = (char *)str;
	i = 0;
	while (i < n)
	{
		*c = 0;
		c++;
		i++;
	}
}
