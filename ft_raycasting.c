/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:43:28 by fballest          #+#    #+#             */
/*   Updated: 2021/01/07 11:07:45 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_keypress(int key, t_map *map)
{
	if (key == W_KEY)
		map->keyw = 1;
	if (key == S_KEY)
		map->keys = 1;
	if (key == A_KEY)
		map->keya = 1;
	if (key == D_KEY)
		map->keyd = 1;
	if (key == ESC_KEY)
		ft_exit_game(map);
	if (key == LEFT_KEY)
		map->keylft = 1;
	if (key == RIGHT_KEY)
		map->keyrgh = 1;
	return (0);
}

int				ft_keyrelease(int key, t_map *map)
{
	if (key == W_KEY)
		map->keyw = 0;
	if (key == S_KEY)
		map->keys = 0;
	if (key == A_KEY)
		map->keya = 0;
	if (key == D_KEY)
		map->keyd = 0;
	if (key == LEFT_KEY)
		map->keylft = 0;
	if (key == RIGHT_KEY)
		map->keyrgh = 0;
	return (0);
}

int				ft_key_hook(t_map *map)
{
	if (map->keys == 1)
	{
		if (map->mapa[(int)(map->posx - map->dirx * MSPD)][(int)(map->posy)]
			== 48)
			map->posx = map->posx - map->dirx * MSPD;
		if (map->mapa[(int)(map->posx)][(int)(map->posy - map->diry * MSPD)]
			== 48)
			map->posy = map->posy - map->diry * MSPD;
	}
	else if (map->keyw == 1)
	{
		if (map->mapa[(int)(map->posx + map->dirx * MSPD)][(int)(map->posy)]
			== 48)
			map->posx = map->posx + map->dirx * MSPD;
		if (map->mapa[(int)(map->posx)][(int)(map->posy + map->diry * MSPD)]
			== 48)
			map->posy = map->posy + map->diry * MSPD;
	}
	ft_key_hook2(map);
	ft_key_hook3(map);
	return (0);
}

void			ft_key_hook2(t_map *map)
{
	if (map->keya == 1)
	{
		if (map->mapa[(int)(map->posx - map->planex * MSPD)][(int)(map->posy)]
			== 48)
			map->posx = map->posx - map->planex * MSPD;
		if (map->mapa[(int)(map->posx)][(int)(map->posy - map->planey * MSPD)]
			== 48)
			map->posy = map->posy - map->planey * MSPD;
	}
	else if (map->keyd == 1)
	{
		if (map->mapa[(int)(map->posx + map->planex * MSPD)][(int)(map->posy)]
			== 48)
			map->posx = map->posx + map->planex * MSPD;
		if (map->mapa[(int)(map->posx)][(int)(map->posy + map->planey * MSPD)]
			== 48)
			map->posy = map->posy + map->planey * MSPD;
	}
}

void			ft_key_hook3(t_map *map)
{
	if (map->keyrgh == 1)
	{
		map->olddirx = map->dirx;
		map->dirx = map->dirx * cos(-RSPD) - map->diry * sin(-RSPD);
		map->diry = map->olddirx * sin(-RSPD) + map->diry * cos(-RSPD);
		map->oldplanex = map->planex;
		map->planex = map->planex * cos(-RSPD) - map->planey * sin(-RSPD);
		map->planey = map->oldplanex * sin(-RSPD) + map->planey * cos(-RSPD);
	}
	else if (map->keylft == 1)
	{
		map->olddirx = map->dirx;
		map->dirx = map->dirx * cos(RSPD) - map->diry * sin(RSPD);
		map->diry = map->olddirx * sin(RSPD) + map->diry * cos(RSPD);
		map->oldplanex = map->planex;
		map->planex = map->planex * cos(RSPD) - map->planey * sin(RSPD);
		map->planey = map->oldplanex * sin(RSPD) + map->planey * cos(RSPD);
	}
}
