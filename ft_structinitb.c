/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structinitb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:23:36 by fballest          #+#    #+#             */
/*   Updated: 2021/01/10 00:10:57 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ft_initmlxe(map);
}

void			ft_initmlxe(t_map *map)
{
	map->sprite = 0;
	map->sprnum = 0;
	map->sprord = 0;
	map->sprdist = 0;
	map->spritex = 0;
	map->spritey = 0;
	map->invdet = 0;
	map->transformx = 0;
	map->transformy = 0;
	map->sprscreenx = 0;
	map->sprheight = 0;
	map->drawstarty = 0;
	map->drawendy = 0;
	map->sprwidth = 0;
	map->drawstartx = 0;
	map->drawendx = 0;
	map->stripe = 0;
	map->texx = 0;
	map->texy = 0;
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
	err->x = 0;
	err->ok = 0;
}

int				ft_rgbtoint(int *hex)
{
	int		rgb;

	rgb = 0;
	rgb = (hex[3] * 1) + (hex[2] * 256) + (hex[1] * 256 * 256);
	return (rgb);
}
