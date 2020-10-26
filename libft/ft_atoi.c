/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:06:07 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 08:57:44 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int							sign;
	unsigned long long int		res;

	sign = 0;
	res = 0;
	while ((*str == 32) || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		if (res < 9223372036854775807)
		{
			res = (res * 10) + (*str - '0');
			str++;
		}
		else
			return ((sign - 1) * 1);
	}
	if (sign == 1)
		return (-res);
	return (res);
}
