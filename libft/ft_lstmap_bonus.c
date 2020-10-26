/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:08:29 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 08:58:44 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*dev;
	t_list		*new;
	t_list		*aux;

	if (!lst || !f)
		return (NULL);
	aux = lst;
	if (!(dev = ft_lstnew(f(aux->content))))
		return (NULL);
	aux = aux->next;
	while (aux)
	{
		if (!(new = ft_lstnew(f(aux->content))))
		{
			ft_lstclear(&dev, del);
			return (NULL);
		}
		ft_lstadd_back(&dev, new);
		aux = aux->next;
	}
	return (dev);
}
