/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:26:27 by fballest          #+#    #+#             */
/*   Updated: 2020/12/01 10:23:11 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_rgbtoint(int *hex)
{
	int		rgb;

	rgb = 0;
	rgb = (hex[3] * 1) + (hex[2] * 256) + (hex[1] * 256 * 256);
	return (rgb);
}

void			ft_printerr(char *str)
{
	write(1, str, ft_strlenb(str));
}
