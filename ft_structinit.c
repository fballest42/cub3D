/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:13:21 by fballest          #+#    #+#             */
/*   Updated: 2020/10/26 10:55:26 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_inibar(t_bar *bar)
{
	bar->x = 0;
	bar->y = 0;
	bar->c = '\0';
	bar->str = NULL;
	bar->line = NULL;
}

int				ft_init(t_map *map, t_tex *tex)
{
	ft_inimap(map);
	ft_initex(tex);
	return (1);
}

void			ft_inimap(t_map *map)
{
	map->i = 0;
	map->res = 0;
	map->rx = 0;
	map->ry = 0;
	map->pla = 0;
	map->px = 0;
	map->py = 0;
	map->file = NULL;
	map->tmp = NULL;
	map->name = "Cub3d by fballest";
	map->okmap = 0;
	map->save = 0;
}

void		ft_initex(t_tex *tex)
{
	tex->no = 0;
	tex->rutano = NULL;
	tex->so = 0;
	tex->rutaso = NULL;
	tex->we = 0;
	tex->rutawe = NULL;
	tex->ea = 0;
	tex->rutaea = NULL;
	tex->sp = 0;
	tex->rutasp = NULL;
	tex->flo[0] = 0;
	tex->flo[1] = 0;
	tex->flo[2] = 0;
	tex->flo[3] = 0;
	tex->fl = 0;
	tex->rutafl = NULL;
	tex->cei[0] = 0;
	tex->cei[1] = 0;
	tex->cei[2] = 0;
	tex->cei[3] = 0;
	tex->ce = 0;
	tex->rutace = NULL;
}
