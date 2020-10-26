/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:30:03 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 08:57:53 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;

	if (!(ptr = malloc(count * size)))
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
