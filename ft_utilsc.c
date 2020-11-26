/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:26:27 by fballest          #+#    #+#             */
/*   Updated: 2020/11/26 09:27:54 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		    ft_hexconv(int num)
{
    int     base_len;
    int     i;
    char    *hex_num;
    char    *base;

    base_len = 16;
    i = 1
    base = "0123456789ABCDEF";
	if (n >= base_len)
		hex_num[i--] = ft_hexconv(n / base_len, base_len, base);
	hex_num[i] = &base[n %  base_len];
}

int         ft_rgbtohex(t_tex *tex, t_map *map)
{
    int     i;

    i = 0;
    map->ceihex = 
}
