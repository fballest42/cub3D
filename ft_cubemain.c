/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/12/30 14:58:40 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_tex *tex)
{
	ft_getdefres(map, tex);
	map->mlx_ptr = mlx_init();
	ft_loadtex(map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->rx, map->ry, map->name);
	mlx_hook(map->mlx_win, 17, 1L << 17, ft_exit_game, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, ft_keypress, map);
	mlx_hook(map->mlx_win, 3, 1L << 1, ft_keyrelease, map);
	mlx_loop_hook(map->mlx_ptr, ft_raycasting, map);
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
	map->texrc[0].ruttex = tex->rutano;
	map->texrc[1].ruttex = tex->rutaso;
	map->texrc[2].ruttex = tex->rutawe;
	map->texrc[3].ruttex = tex->rutaea;
	map->texrc[4].ruttex = tex->rutasp;
	map->sprite = malloc(sizeof(double) * map->rx + 1);
	map->sprord = malloc(sizeof(int) * map->sprnum + 1);
	map->sprdist = malloc(sizeof(double) * map->sprnum + 1);
	ft_getinfo(map);
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

int				ft_raycasting(t_map *map)
{
	int			x;

	x = 0;
	ft_key_hook(map);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->rx, map->ry);
	map->mlx_imgaddr = mlx_get_data_addr(map->mlx_img, &map->mlx_bxp,
		&map->mlx_sili, &map->mlx_endian);
	while (x < map->rx)
	{
		ft_setinfo(x, map);
		ft_initialstep(map);
		ft_hitwall(map);
		ft_heightdraw(map);
		ft_painttex(map);
		ft_verline(x, map);
		x++;
	}
	ft_raycastingb(map);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
	//ft_copyimage(map);
	mlx_destroy_image(map->mlx_ptr, map->mlx_img);
	return (0);
}

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
				ft_paintspr(map, i);
			map->stripe++;
		}
	}
}

void			ft_paintspr(t_map *map, int i)
{
	int					y;
	int					d;
	unsigned int		color;

	y = map->drawstarty;
	while(y < map->drawendy)
	{
		d = (y) * 256 - map->ry * 128 + map->sprheight * 128;
		map->texy = ((d * map->texheight) / map->sprheight) / 256;
		color = *(unsigned int*)(map->texrc[4].addr + (y * map->texrc[4].sizeli
			+ map->stripe * (map->texrc[4].bpptex / 8)));
		if ((color & 0x00FFFFFF) != 0)
			ft_mlx_pixel_put(map, map->stripe, y, color);
	}
}

void			ft_calculatespr(t_map *map, int i)
{
	map->spritex = map->sprpos[map->sprord[i]].0 - map->posx;
	map->spritey = map->sprpos[map->sprord[i]].1 - map->posy;
	map->invdet = 1.0 / (map->planex * map->diry - map->dirx * map->planey);
	map->transformx = map->invdet * (map->diry + map->spritex - map->dirx * map->spritey);
	map->transformy = map->invdet * (-map->planey * map->spritex + map->planex * map->spritey);
	map->sprscreenx = (int)((map->rx / 2) * (1 + map->transforx / map->transformy));
	map->sprheight = abs(int(map->ry / (map->transformy)));
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

void			ft_sortsprites(t_map * map)
{
	int		y;

	y = 0;
	while (y < map->sprnum)
	{
		map->sprord[y] = y;
		map->sprdist[y] = (int)((map->posx - map->sprpos[y][0]) *
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

	i = 0;
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
		if (map->mapa[map->mapx][map->mapy] > 48)
			map->hit = 1;
	}
}

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

void			ft_wallident(t_map *map)
{
	if (map->side == 0 && map->raydirx > 0)//NO Texture
		map->tex_id = 0;
	if (map->side == 0 && map->raydirx <= 0)//SO Texture
		map->tex_id = 1;
	if (map->side == 1 && map->raydiry > 0)//WE Texture
		map->tex_id = 2;
	if (map->side == 1 && map->raydiry <= 0)//EA Texture
		map->tex_id = 3;
}

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
	exit(0);
	return (0);
}
