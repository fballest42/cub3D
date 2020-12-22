/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:13:21 by fballest          #+#    #+#             */
/*   Updated: 2020/12/22 11:17:10 by fballest         ###   ########.fr       */
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
	map->time = 0;
	map->oldtime = 0;
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

void			ft_initmlxc(t_map *map)
{
	map->texrc[0].img = NULL;
	map->texrc[1].img = NULL;
	map->texrc[2].img = NULL;
	map->texrc[3].img = NULL;
	map->texrc[4].img = NULL;
	map->texrc[0].addr = NULL;
	map->texrc[1].addr = NULL;
	map->texrc[2].addr = NULL;
	map->texrc[3].addr = NULL;
	map->texrc[4].addr = NULL;
	map->texrc[0].sizeli = 0;
	map->texrc[1].sizeli = 0;
	map->texrc[2].sizeli = 0;
	map->texrc[3].sizeli = 0;
	map->texrc[4].sizeli = 0;
	map->texrc[0].bpptex = 0;
	map->texrc[1].bpptex = 0;
	map->texrc[2].bpptex = 0;
	map->texrc[3].bpptex = 0;
	map->texrc[4].bpptex = 0;
	map->texx = 0;
	map->texy = 0;
	ft_initmlxd(map);
}

void			ft_initmlxd(t_map *map)
{
	map->texrc[0].endian = 0;
	map->texrc[1].endian = 0;
	map->texrc[2].endian = 0;
	map->texrc[3].endian = 0;
	map->texrc[4].endian = 0;
	map->texrc[0].ruttex = NULL;
	map->texrc[1].ruttex = NULL;
	map->texrc[2].ruttex = NULL;
	map->texrc[3].ruttex = NULL;
	map->texrc[4].ruttex = NULL;
	map->texheight = 0;
	map->texwidth = 0;
	map->texside = 0;
	map->sprite = 0;
	map->sprnum = 0;
	map->sprord = 0;
	map->sprdist = 0;
}

void			ft_inierr(t_err *err)
{
	err->err1 = "Error\n1.- Invalid number of arguments.\n";
	err->err2 = "Error\n2.- Not valid map extension.\n";
	err->err3 = "Error\n3.- Invalid arguments.\n";
	err->err4 = "Error\n4.- Could not open the file.\n";
	err->err5 = "Error\n5.- Not defined or not valid resolution.\n";
	err->err6 = "Error\n6.- Not a valid texture extension.\n";
	err->err7 = "Error\n7.- Not valid info on Resolution, Ceiling or Floor.\n";
	err->err8 = "Error\n8.- Ceiling or Floor must use ',' between values.\n";
	err->err9 = "Error\n9.- Blank line in the middle of the map.\n";
	err->err10 = "Error\n10.- No such file or directory for texture file.\n";
	err->err11 = "Error\n11.- No ceiling colour defined.\n";
	err->err12 = "Error\n12.- No floor colour defined.\n";
	err->err13 = "Error\n13.- Wrong colour for ceiling or floor.\n";
	err->err14 = "Error\n14.- Duplicate parameter.\n";
	err->err15 = "Error\n15.- Not valid map.\n";
	err->err16 = "Error\n16.- Wrong number of players on map.\n";
	err->err17 = "Error\n17.- Not valid parameters in the map file.\n";
	err->err18 = "Error\n18.- Not valid symbols included in the map.\n";
	err->err19 = "Error\n19.- Could not open a texture file.\n";
	err->err20 = "Error\n20.- Not valid texture extension.\n";
	err->err21 = "Error\n21.- Not a coma between colours.\n";
	err->err22 = "Error\n22.- .\n";
	err->err23 = "Error\n23.- .\n";
	err->x = 0;
	err->ok = 0;
}
