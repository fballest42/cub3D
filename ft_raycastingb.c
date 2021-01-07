/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycastingb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:26:27 by fballest          #+#    #+#             */
/*   Updated: 2021/01/07 11:14:17 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_setinfo(int x, t_map *map)
{
	map->camerax = 2 * x / (double)(map->rx) - 1;
	map->raydirx = map->dirx + map->planex * map->camerax;
	map->raydiry = map->diry + map->planey * map->camerax;
	map->mapx = (int)map->posx;
	map->mapy = (int)map->posy;
	map->deltadistx = fabs(1 / map->raydirx);
	map->deltadisty = fabs(1 / map->raydiry);
}

void			ft_wallident(t_map *map)
{
	if (map->side == 0 && map->raydirx > 0)
		map->tex_id = 0;
	if (map->side == 0 && map->raydirx <= 0)
		map->tex_id = 1;
	if (map->side == 1 && map->raydiry > 0)
		map->tex_id = 2;
	if (map->side == 1 && map->raydiry <= 0)
		map->tex_id = 3;
}

void			ft_loadtex(t_map *map)
{
	map->texrc[0].img = mlx_xpm_file_to_image(map->mlx_ptr,
		map->texrc[0].ruttex, &map->texwidth, &map->texheight);
	map->texrc[0].addr = mlx_get_data_addr(map->texrc[0].img,
		&map->texrc[0].bpptex, &map->texrc[0].sizeli, &map->texrc[0].endian);
	map->texrc[1].img = mlx_xpm_file_to_image(map->mlx_ptr,
		map->texrc[1].ruttex, &map->texwidth, &map->texheight);
	map->texrc[1].addr = mlx_get_data_addr(map->texrc[1].img,
		&map->texrc[1].bpptex, &map->texrc[1].sizeli, &map->texrc[1].endian);
	map->texrc[2].img = mlx_xpm_file_to_image(map->mlx_ptr,
		map->texrc[2].ruttex, &map->texwidth, &map->texheight);
	map->texrc[2].addr = mlx_get_data_addr(map->texrc[2].img,
		&map->texrc[2].bpptex, &map->texrc[2].sizeli, &map->texrc[2].endian);
	map->texrc[3].img = mlx_xpm_file_to_image(map->mlx_ptr,
		map->texrc[3].ruttex, &map->texwidth, &map->texheight);
	map->texrc[3].addr = mlx_get_data_addr(map->texrc[3].img,
		&map->texrc[3].bpptex, &map->texrc[3].sizeli, &map->texrc[3].endian);
	map->texrc[4].img = mlx_xpm_file_to_image(map->mlx_ptr,
		map->texrc[4].ruttex, &map->texwidth, &map->texheight);
	map->texrc[4].addr = mlx_get_data_addr(map->texrc[4].img,
		&map->texrc[4].bpptex, &map->texrc[4].sizeli, &map->texrc[4].endian);
}

void			ft_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->mlx_imgaddr + (y * map->mlx_sili + x * (map->mlx_bxp / 8));
	*(unsigned int *)dst = color;
}

int				ft_getpixel(t_map *map, int x, int y)
{
	char	*dst;

	dst = map->texrc[map->tex_id].addr + (y * map->texrc[map->tex_id].sizeli
		+ x * (map->texrc[map->tex_id].bpptex / 8));
	return (*(unsigned int*)dst);
}
