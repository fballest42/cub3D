/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:13:21 by fballest          #+#    #+#             */
/*   Updated: 2021/01/07 10:25:18 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_init(t_map *map, t_tex *tex, t_err *err)
{
	ft_inimap(map);
	ft_initex(tex);
	ft_inierr(err);
	ft_initmlx(map);
	return (1);
}

void			ft_inimap(t_map *map)
{
	map->i = 0;
	map->res = 0;
	map->rx = 0;
	map->ry = 0;
	map->grx = 0;
	map->gry = 0;
	map->pla = 0;
	map->px = 0;
	map->py = 0;
	map->fm = 0;
	map->lm = 0;
	map->im = 0;
	map->por = 0;
	map->cei = 0;
	map->flo = 0;
	map->file = NULL;
	map->name = "cub3D";
	map->mapa = NULL;
	map->okmap = 0;
	map->save = 0;
}

void			ft_initmlx(t_map *map)
{
	map->mlx_ptr = NULL;
	map->mlx_win = NULL;
	map->mlx_img = NULL;
	map->mlx_imgaddr = NULL;
	map->mlx_bxp = 0;
	map->mlx_sili = 0;
	map->mlx_endian = 0;
	map->posx = 0;
	map->posy = 0;
	map->dirx = 0;
	map->diry = 0;
	map->planex = 0;
	map->planey = 0;
	map->camerax = 0;
	map->raydirx = 0;
	map->raydiry = 0;
	map->olddirx = 0.0;
	map->oldplanex = 0.0;
	map->wcol = 16711680;
	map->tex_id = 0;
	ft_initmlxb(map);
}

void			ft_initmlxb(t_map *map)
{
	map->sidedistx = 0;
	map->sidedisty = 0;
	map->mapx = 0;
	map->mapy = 0;
	map->deltadistx = 0;
	map->deltadisty = 0;
	map->perpwalldist = 0;
	map->stepx = 0;
	map->stepy = 0;
	map->hit = 0;
	map->side = 0;
	map->lineheight = 0;
	map->drawstart = 0;
	map->drawend = 0;
	map->keyw = 0;
	map->keys = 0;
	map->keya = 0;
	map->keyd = 0;
	map->keyesc = 0;
	map->keylft = 0;
	map->keyrgh = 0;
	map->wallx = 0.0;
	map->texx = 0.0;
	map->texy = 0.0;
	ft_initmlxc(map);
}

void			ft_initex(t_tex *tex)
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
