/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:26:27 by fballest          #+#    #+#             */
/*   Updated: 2020/11/27 13:39:45 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_rgbtoint(int *hex)
{
	int		b;
	int		g;
	int		r;
	int		rgb;

	b = hex[1] * 1;
	g = hex[2] * 256;
	r = hex[3] * 256 * 256;
	rgb = b + g + r;
	return (rgb);
}

void			ft_printerr(char *str)
{
	write(1, str, ft_strlenb(str));
}
