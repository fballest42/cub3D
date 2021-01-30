/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycastinge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:26:27 by fballest          #+#    #+#             */
/*   Updated: 2021/01/30 11:33:05 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_getdefres(t_map *map, t_tex *tex)
{
	mlx_get_screen_size(map->mlx_ptr, &map->grx, &map->gry);
	if (map->rx == 2560 && map->ry == 1440 && map->save == 0)
	{
		map->rx = map->grx;
		map->ry = map->gry;
	}
	map->cei = ft_rgbtoint(tex->cei);
	map->flo = ft_rgbtoint(tex->flo);
	map->texrc[0].ruttex = tex->rutano;
	map->texrc[1].ruttex = tex->rutaso;
	map->texrc[2].ruttex = tex->rutawe;
	map->texrc[3].ruttex = tex->rutaea;
	map->texrc[4].ruttex = tex->rutasp;
	map->sprite = malloc(sizeof(double) * map->rx + 1);
	map->sprord = malloc(sizeof(int) * map->sprnum + 1);
	map->sprdist = malloc(sizeof(double) * map->sprnum + 1);
	free(tex);
	ft_getinfo(map);
}

void			ft_initialstep(t_map *map)
{
	map->hit = 0;
	if (map->raydirx < 0)
	{
		map->stepx = -1;
		map->sidedistx = (map->posx - map->mapx) * map->deltadistx;
	}
	else
	{
		map->stepx = 1;
		map->sidedistx = (map->mapx + 1.0 - map->posx) * map->deltadistx;
	}
	if (map->raydiry < 0)
	{
		map->stepy = -1;
		map->sidedisty = (map->posy - map->mapy) * map->deltadisty;
	}
	else
	{
		map->stepy = 1;
		map->sidedisty = (map->mapy + 1.0 - map->posy) * map->deltadisty;
	}
}

void			ft_hitwall(t_map *map)
{
	while (map->hit == 0)
	{
		if (map->sidedistx < map->sidedisty)
		{
			map->sidedistx = map->sidedistx + map->deltadistx;
			map->mapx = map->mapx + map->stepx;
			map->side = 0;
		}
		else
		{
			map->sidedisty = map->sidedisty + map->deltadisty;
			map->mapy = map->mapy + map->stepy;
			map->side = 1;
		}
		if (map->mapa[map->mapx][map->mapy] == 49)
			map->hit = 1;
	}
}

void			ft_getinfo(t_map *map)
{
	map->posx = map->px + 0.5;
	map->posy = map->py + 0.5;
	if (map->por == 'N')
	{
		map->dirx = -1;
		map->planey = 0.66;
	}
	else if (map->por == 'S')
	{
		map->dirx = 1;
		map->planey = -0.66;
	}
	else if (map->por == 'W')
	{
		map->diry = -1;
		map->planex = -0.66;
	}
	else if (map->por == 'E')
	{
		map->diry = 1;
		map->planex = 0.66;
	}
}
