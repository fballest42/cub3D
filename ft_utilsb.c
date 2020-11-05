/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:16:03 by fballest          #+#    #+#             */
/*   Updated: 2020/11/05 14:19:40 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_strchrb(char *s, int c)
{
	char			*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

char		*ft_substrb(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*dst;
	size_t			size;

	i = 0;
	if (!s)
		return (0);
	i = ft_strlenb(s);
	if (i < start)
		return (ft_strdupb(""));
	size = ft_strlenb(s + start);
	if (size < len)
		len = size;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int			ft_outspace(int i, char *str)
{
	while ((str[i]) && (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t'))
		i++;
	return (i);
}

int			ft_checkspace(t_map *map)
{
	int		i;

	i = 0;
	while (map->file[i] != '\0')
	{
		if (map->file[i] == ' ' || map->file[i] == '1' || map->file[i] == '2'
			|| map->file[i] == '0' || map->file[i] == 'N' || map->file[i] == 'S'
			|| map->file[i] == 'W' || map->file[i] == 'E' || map->file[i] == '\n')
		{
			i++;
			map->okmap = 1;
		}
		else
			return (-1);
	}
	return (map->okmap);
}

void		ft_freemem(t_map *map, t_tex *tex, t_err *err)
{
	if (map->file)
		free(map->file);
	if (map->mapa)
		ft_freemap(map);
	if (tex->rutano)
		free(tex->rutano);
	if (tex->rutaso)
		free(tex->rutaso);
	if (tex->rutawe)
		free(tex->rutawe);
	if (tex->rutaea)
		free(tex->rutaea);
	if (tex->rutasp)
		free(tex->rutasp);
	ft_init(map, tex, err);
	ft_delerr(err);
	map->name = NULL;
	free(map);
	free(err);
	free(tex);
}

void		ft_freemap(t_map *map)
{
	int		x;

	x = 0;
	while (map->mapa[x] != NULL)
	{
		free(map->mapa[x]);
		map->mapa[x] = NULL;
		x++;
	}
	free(map->mapa);
	map->mapa = NULL;
}

void		ft_freearray(char **str)
{
	int		x;

	x = 0;
	if (str[x])
	{
		while (str[x])
		{
			str[x] = NULL;
			free(str[x]);
			x++;
		}
	}
	if (str)
		free(str);
}

void		ft_delerr(t_err *err)
{
	err->err1 = NULL;
	err->err2 = NULL;
	err->err3 = NULL;
	err->err4 = NULL;
	err->err5 = NULL;
	err->err6 = NULL;
	err->err7 = NULL;
	err->err8 = NULL;
	err->err9 = NULL;
	err->err10 = NULL;
	err->err11 = NULL;
	err->err12 = NULL;
	err->err13 = NULL;
	err->err14 = NULL;
	err->err15 = NULL;
	err->err16 = NULL;
	err->err17 = NULL;
	err->err18 = NULL;
	err->err19 = NULL;
	err->err20 = NULL;
	err->err21 = NULL;
	err->err22 = NULL;
	err->err23 = NULL;
	err->x = 0;
	err->ok = 0;
}

/*void		ft_delpointer(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
			str[i] = '\0';
		free(str);
		str = NULL;
	}
}

void		ft_delarray(char **str)
{

}*/
