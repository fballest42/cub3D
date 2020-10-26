/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:16:03 by fballest          #+#    #+#             */
/*   Updated: 2020/10/26 10:51:10 by fballest         ###   ########.fr       */
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

int		ft_outspace(int i, char *str)
{
	while ((str[i]) && (str[i] == ' ' || str[i] == ','
		|| str[i] == '\n'))
		i++;
	return (i);
}

int			ft_checkspace(t_map *map)
{
	int		i;

	i = 0;
	while (*map->file[i] != '\0')
	{
		if (*map->file[i] == ' ' || *map->file[i] == '1' || *map->file[i] == '2'
			|| *map->file[i] == '0' || *map->file[i] == 'N' || *map->file[i] == 'S'
			|| *map->file[i] == 'W' || *map->file[i] == 'E' || *map->file[i] == '\n')
		{
			i++;
			map->okmap = 1;
		}
		else
			return (-1);
	}
	return (map->okmap);
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
