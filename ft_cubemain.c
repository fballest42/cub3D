/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/11/27 22:24:09 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_err *err, t_tex *tex)
{
	tex->rutano = err->err6;
	map->mlx_ptr = mlx_init();
	ft_getdefres(map, tex);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->rx, map->ry, map->name);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->rx, map->ry);
	map->mlx_imgaddr = mlx_get_data_addr(map->mlx_ptr, &map->mlx_bxp,
		&map->mlx_sili, &map->mlx_endian);

	int		offset = (map->ry * map->mlx_sili + map->rx * (map->mlx_bxp / 8));
	mlx_loop(map->mlx_ptr);
	return (0);
}

void			ft_getdefres(t_map *map, t_tex *tex)
{
	mlx_get_screen_size(map->mlx_ptr, &map->grx, &map->gry);
	if (map->rx == 2560 && map->ry == 1440)
	{
		map->rx = map->grx;
		map->ry = map->gry;
	}
	map->cei = ft_rgbtoint(tex->cei);
	map->flo = ft_rgbtoint(tex->flo);
}

void            ft_mlx_pixel_put(t_map *map, int x, int y, int color)
{
    char    *dst;

    dst = map->mlx_addr + (y * map->mlx_sili + x * (map->mlx_bxp / 8));
    *(unsigned int *)dst = color;
}

void			ft_paint_cei_flo(t_map *map)
{

}
