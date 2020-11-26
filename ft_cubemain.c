/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/11/25 18:36:04 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_err *err, t_tex *tex)
{
	tex->rutano = err->err6;
	map->mlx_ptr = mlx_init();
	mlx_get_screen_size(map->mlx_ptr, &map->grx, &map->gry);
	ft_getdefres(map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->rx, map->ry, map->name);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->rx, map->ry)
	;
	mlx_loop(map->mlx_ptr);
	return (0);
}

void			ft_getdefres(t_map *map)
{
	if (map->rx == 2560 && map->ry == 1440)
	{
		map->rx = map->grx;
		map->ry = map->gry;
	}
}
