/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:23:01 by fballest          #+#    #+#             */
/*   Updated: 2020/11/08 18:31:07 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strlenb(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int			ft_strncmpb(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((ss1[i] != '\0' || ss2[i] != '\0') && i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

char		*ft_strdupb(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(ft_strlenb(str) + 1)))
		return(0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

char		*ft_strjoinb(char *str, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	if(!(dest = malloc(ft_strlenb(str) + ft_strlenb(s2) + 1)))
		return(0);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(str);
	return(dest);
}

int			ft_freestruct(t_map *map, t_tex *tex)
{
	ft_initex(tex);
	ft_inimap(map);
	free(tex);
	free(map);
	return (-1);
}
