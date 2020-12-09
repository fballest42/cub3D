/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/12/09 13:57:05 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_err *err, t_tex *tex)
{
	tex->rutano = err->err6; /*OJO ELIMINAR SOLO HABILITADO PARA PASAR ERR*/
	map->mlx_ptr = mlx_init();
	ft_getdefres(map, tex);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->rx, map->ry, map->name);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->rx, map->ry);
	map->mlx_imgaddr = mlx_get_data_addr(map->mlx_img, &map->mlx_bxp,
		&map->mlx_sili, &map->mlx_endian);
	mlx_hook(map->mlx_win, 17, 1L << 17, ft_exit_game, map);
	//mlx_hook(map->mlx_win, 2, 1L << 0, ft_keypress, map);
	//mlx_hook(map->mlx_win, 3, 1L << 1, ft_keyrelease, map);
	//ft_paint_cei_flo(map, 0, 0);
	//mlx_loop_hook(map->mlx_ptr, ft_paint_cei_flo, map);
	mlx_loop_hook(map->mlx_ptr, ft_raycasting, map);
	mlx_key_hook(map->mlx_win, ft_key_hook, map);
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
	ft_getinfo(map);
}

void			ft_getinfo(t_map *map)
{
	map->posX = map->px;
	map->posY = map->py;
	if (map->por == 'N')
	{
		map->dirX = -1;
		map->planeY = 0.66;
	}
	else if (map->por == 'S')
	{
		map->dirX = 1;
		map->planeY = -0.66;
	}
	else if (map->por == 'W')
	{
		map->dirY = -1;
		map->planeX = -0.66;
	}
	else if (map->por == 'E')
	{
		map->dirY = 1;
		map->planeX = 0.66;
	}
}

void			ft_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->mlx_imgaddr + (y * map->mlx_sili + x * (map->mlx_bxp / 8));
	*(unsigned int *)dst = color;
}

int				ft_raycasting(t_map *map)
{
	int			x;

	x = 0;
	while (x < map->rx)
	{
		map->cameraX = 2 * x / (double)(map->rx) - 1;
		map->rayDirX = map->dirX + map->planeX * map->cameraX;
		map->rayDirY = map->dirY + map->planeY * map->cameraX;
		map->mapX = (int)map->posX;
		map->mapY = (int)map->posY;
		map->deltaDistX = fabs(1 / map->rayDirX);
		map->deltaDistY = fabs(1 / map->rayDirY);
		ft_initialstep(map);
		ft_hitwall(map);
		ft_heightdraw(map);
		ft_verLine(x, map);
		x++;
	}
	return (0);
}

void			ft_initialstep(t_map *map)
{
	if (map->rayDirX < 0)
	{
		map->stepX = -1;
		map->sideDistX = (map->posX - map->mapX) * map->deltaDistX;
	}
	else
	{
		map->stepX = 1;
		map->sideDistX = (map->mapX + 1.0 - map->posX) * map->deltaDistX;
	}
	if (map->rayDirY < 0)
	{
		map->stepY = -1;
		map->sideDistY = (map->posY - map->mapY) * map->deltaDistY;
	}
	else
	{
		map->stepY = 1;
		map->sideDistY = (map->mapY + 1.0 - map->posY) * map->deltaDistY;
	}
}

void			ft_hitwall(t_map *map)
{
	while (map->hit == 0)
	{
		if (map->sideDistX < map->sideDistY)
		{
			map->sideDistX = map->sideDistX + map->deltaDistX;
			map->mapX = map->mapX + map->stepX;
			map->side = 0;
		}
		else
		{
			map->sideDistY = map->sideDistY + map->deltaDistY;
			map->mapY = map->mapY + map->stepY;
			map->side = 1;
		}
		if (map->mapa[map->mapX][map->mapY] > 0)
			map->hit = 1;
	}
}

void			ft_heightdraw(t_map *map)
{
	if (map->side == 0)
		map->perpWallDist = (map->mapX - map->posX + (1 - map->stepX) / 2) / map->rayDirX;
	else
		map->perpWallDist = (map->mapY - map->posY + (1 - map->stepY) / 2) / map->rayDirY;
	map->lineHeight = (int)(map->ry / map->perpWallDist);
	map->drawStart = -map->lineHeight / 2 + map->ry / 2;
	if (map->drawStart < 0)
		map->drawStart = 0;
	map->drawEnd = map->lineHeight / 2 + map->ry / 2;
	if (map->drawEnd <= map->ry)
		map->drawEnd = map->ry - 1;
}

void			ft_verLine(int x, t_map *map)
{
	int		cc;
	int		fc;
	int		y;

	y = 0;
	cc = map->cei;
	fc = map->flo;
	while (y < map->drawStart)
	{
		ft_mlx_pixel_put(map, x, y, cc);
		y++;
	}
	while (y < map->drawEnd)
	{
		ft_mlx_pixel_put(map, x, y, 16711680);
		y++;
	}
	while (y < map->rx)
	{
		ft_mlx_pixel_put(map, x, y, fc);
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
}

int				ft_paint_player(t_map *map, int x, int y)
{
	int		px;
	int		py;

	px = x;
	py = y;
	while (px < (x + 10))
	{
		py = y;
		while (py < (y + 10))
		{
			ft_mlx_pixel_put(map, px, py, 658956);
			py++;
		}
		px++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
	return (0);
}

int			ft_paint_cei_flo(t_map *map, int x, int y)
{
	while (x < map->rx)
	{
		y = 0;
		while (y < map->ry)
		{
			if (y < (map->ry / 2))
				ft_mlx_pixel_put(map, x, y, map->cei);
			else if (y >= (map->ry / 2))
				ft_mlx_pixel_put(map, x, y, map->flo);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
	return (0);
}

int				ft_key_hook(int keycode, t_map *map)
{
	if (keycode == S_KEY)
	{
		if (map->mapa[(int)(map->posX - map->dirX * mspd)][(int)(map->posY)]
			== 0)
			map->posX = map->posX - map->dirX * mspd;
		if (map->mapa[(int)(map->posX)][(int)(map->posY - map->dirY * mspd)]
			== 0)
			map->posY = map->posY - map->dirY * mspd;
	}
	else if (keycode == W_KEY)
	{
		if (map->mapa[(int)(map->posX + map->dirX * mspd)][(int)(map->posY)]
			== 0)
			map->posX = map->posX + map->dirX * mspd;
		if (map->mapa[(int)(map->posX)][(int)(map->posY + map->dirY * mspd)]
			== 0)
			map->posY = map->posY + map->dirY * mspd;
	}
	else if (keycode == A_KEY)
	{
		if (map->mapa[(int)(map->posX - map->planeX * mspd)][(int)(map->posY)]
			== 0)
			map->posX = map->posX - map->planeX * mspd;
		if (map->mapa[(int)(map->posX)][(int)(map->posY - map->planeY * mspd)]
			== 0)
			map->posY = map->posY - map->planeY * mspd;
	}
	else if (keycode == D_KEY)
	{
		if (map->mapa[(int)(map->posX + map->planeX * mspd)][(int)(map->posY)]
			== 0)
			map->posX = map->posX + map->planeX * mspd;
		if (map->mapa[(int)(map->posX)][(int)(map->posY + map->planeY * mspd)]
			== 0)
			map->posY = map->posY + map->planeY * mspd;
	}
	else if (keycode == ESC_KEY)
		ft_exit_game(map);
	else if (keycode == LEFT_KEY)
		printf("%s\n", "rotate left");
	else if (keycode == RIGHT_KEY)
		printf("%s\n", "rotate right");
	else if (keycode == X_BTN)
		printf("%s\n", "???");
	else if (keycode == LEFT_SHIFT)
		printf("%s\n", "faster");
	map->rx = map->rx + (1 * 0);
	return (0);
	ft_raycasting(map);
}

int				ft_exit_game(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	map->mlx_ptr = NULL;
	free(map->mlx_ptr);
	free(map->mlx_img);
	exit(0);
	return (0);
}
