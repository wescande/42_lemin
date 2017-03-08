/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 01:43:42 by wescande          #+#    #+#             */
/*   Updated: 2016/12/29 03:01:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

static void		delete_room(t_ld *lst)
{
	while (lst)
	{
		ft_strdel(&((t_room *)lst->content)->name);
		ft_ld_clear(&((t_room*)lst->content)->connect, NULL);
		lst = lst->next;
	}
}

void			lem_in_exit(t_lem *lem)
{
	delete_room(lem->room);
	ft_ld_clear(&lem->room, &ft_memdel);
}
