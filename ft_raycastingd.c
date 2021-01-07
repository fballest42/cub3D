/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycastingd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:26:27 by fballest          #+#    #+#             */
/*   Updated: 2021/01/07 11:31:14 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_raycastingb(t_map *map)
{
	int		i;

	i = 0;
	ft_sortsprites(map);
	while (i < map->sprnum)
	{
		ft_calculatespr(map, i);
		while (map->stripe < map->drawendx)
		{
			map->texx = (int)(256 * (map->stripe - (-map->sprwidth / 2
				+ map->sprscreenx)) * map->texwidth / map->sprwidth) / 256;
			if (map->transformy > 0 && map->stripe > 0 && map->stripe < map->rx
				&& map->transformy < map->sprite[map->stripe])
				ft_paintspr(map);
			map->stripe++;
		}
		i++;
	}
}

void			ft_paintspr(t_map *map)
{
	int					y;
	int					d;
	unsigned int		color;

	y = map->drawstarty;
	map->tex_id = 4;
	while (y < map->drawendy)
	{
		d = (y) * 256 - map->ry * 128 + map->sprheight * 128;
		map->texy = ((d * map->texheight) / map->sprheight) / 256;
		color = *(unsigned int*)(map->texrc[map->tex_id].addr +
			(map->texy * map->texrc[map->tex_id].sizeli
			+ map->texx * (map->texrc[map->tex_id].bpptex / 8)));
		if ((color & 0x00FFFFFF) != 0)
			ft_mlx_pixel_put(map, map->stripe, y, color);
		y++;
	}
}

void			ft_calculatespr(t_map *map, int i)
{
	map->spritex = (map->sprpos[map->sprord[i]][0] - (map->posx - 0.5));
	map->spritey = (map->sprpos[map->sprord[i]][1] - (map->posy - 0.5));
	map->invdet = 1.0 / (map->planex * map->diry - map->dirx * map->planey);
	map->transformx = map->invdet * (map->diry * map->spritex -
		map->dirx * map->spritey);
	map->transformy = map->invdet * (-map->planey * map->spritex +
		map->planex * map->spritey);
	map->sprscreenx = (int)((map->rx / 2) * (1 + map->transformx /
		map->transformy));
	map->sprheight = abs((int)(map->ry / (map->transformy)));
	map->drawstarty = -map->sprheight / 2 + map->ry / 2;
	if (map->drawstarty < 0)
		map->drawstarty = 0;
	map->drawendy = map->sprheight / 2 + map->ry / 2;
	if (map->drawendy >= map->ry)
		map->drawendy = map->ry - 1;
	map->sprwidth = abs((int)(map->ry / (map->transformy)));
	map->drawstartx = -map->sprwidth / 2 + map->sprscreenx;
	if (map->drawstartx < 0)
		map->drawstartx = 0;
	map->drawendx = map->sprwidth / 2 + map->sprscreenx;
	if (map->drawendx >= map->rx)
		map->drawendx = map->rx - 1;
	map->stripe = map->drawstartx;
}

void			ft_sortsprites(t_map *map)
{
	int		y;

	y = 0;
	while (y < map->sprnum)
	{
		map->sprord[y] = y;
		map->sprdist[y] = ((map->posx - map->sprpos[y][0]) *
			(map->posx - map->sprpos[y][0]) + (map->posy - map->sprpos[y][1])
			* (map->posy - map->sprpos[y][1]));
		y++;
	}
	ft_sortspritesb(map);
}

void			ft_sortspritesb(t_map *map)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	while (i < map->sprnum)
	{
		j = i + 1;
		while (j < map->sprnum)
		{
			if (map->sprdist[map->sprord[i]] < map->sprdist[map->sprord[j]])
			{
				temp = map->sprord[i];
				map->sprord[i] = map->sprord[j];
				map->sprord[j] = temp;
			}
			j++;
		}
		i++;
	}
}
