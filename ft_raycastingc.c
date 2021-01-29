/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycastingc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:26:27 by fballest          #+#    #+#             */
/*   Updated: 2021/01/29 12:49:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_heightdraw(t_map *map)
{
	if (map->side == 0)
		map->perpwalldist = (map->mapx - map->posx +
		(1 - map->stepx) / 2) / map->raydirx;
	else
		map->perpwalldist = (map->mapy - map->posy +
		(1 - map->stepy) / 2) / map->raydiry;
	map->lineheight = (int)(map->ry / map->perpwalldist);
	map->drawstart = -map->lineheight / 2 + map->ry / 2;
	if (map->drawstart < 0)
		map->drawstart = 0;
	map->drawend = map->lineheight / 2 + map->ry / 2;
	if (map->drawend >= map->ry)
		map->drawend = map->ry - 1;
}

void			ft_verline(int x, t_map *map)
{
	int		cc;
	int		fc;
	int		y;

	y = 0;
	cc = map->cei;
	fc = map->flo;
	map->sprite[x] = map->perpwalldist;
	while (y < map->ry)
	{
		if (y < map->drawstart)
			ft_mlx_pixel_put(map, x, y, cc);
		else if (y >= map->drawstart && y <= map->drawend)
			ft_mlx_pixel_put(map, x, y, 1711276032);
		else if (y > map->drawend)
			ft_mlx_pixel_put(map, x, y, fc);
		y++;
	}
	y = map->drawstart;
	ft_painttexb(map, x, y);
}

void			ft_painttex(t_map *map)
{
	ft_wallident(map);
	if (map->side == 0)
		map->wallx = map->posy + map->perpwalldist * map->raydiry;
	else
		map->wallx = map->posx + map->perpwalldist * map->raydirx;
	map->wallx = map->wallx - floor(map->wallx);
	map->texx = (int)(map->wallx * (double)map->texwidth);
	if (map->side == 0 && map->raydirx > 0)
		map->texx = map->texwidth - map->texx - 1;
	if (map->side == 1 && map->raydiry < 0)
		map->texx = map->texwidth - map->texx - 1;
}

void			ft_painttexb(t_map *map, int x, int y)
{
	map->step = 1.0 * map->texheight / map->lineheight;
	map->texpos = (map->drawstart - map->ry / 2 + map->lineheight / 2)
		* map->step;
	while (y <= map->drawend)
	{
		map->texy = (int)map->texpos & (map->texheight - 1);
		map->texpos = map->texpos + map->step;
		ft_mlx_pixel_put(map, x, y, ft_getpixel(map, map->texx, map->texy));
		y++;
	}
}

int				ft_exit_game(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	map->mlx_ptr = NULL;
	free(map->mlx_ptr);
	map->sprite = 0;
	map->sprord = 0;
	map->sprdist = 0;
	free(map->sprite);
	free(map->sprord);
	free(map->sprdist);
	free(map);
	exit(0);
	return (0);
}
