/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:07:06 by fballest          #+#    #+#             */
/*   Updated: 2020/10/08 15:08:54 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!(s == NULL))
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
