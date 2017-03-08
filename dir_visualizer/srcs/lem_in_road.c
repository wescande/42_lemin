/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_road.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:43:06 by wescande          #+#    #+#             */
/*   Updated: 2016/12/29 09:39:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

t_room			*get_room_type(t_ld *lst, int type)
{
	t_room	*my_room;

	my_room = NULL;
	while (lst && !my_room)
	{
		if (((t_room *)lst->content)->type == type)
			my_room = (t_room *)lst->content;
		lst = lst->next;
	}
	return (my_room);
}

static int		get_smaller(t_room *room, int pos)
{
	int		depth;
	int		receveid;
	t_ld	*connect;

	depth = 0;
	if (room->type == -1)
		return (pos);
	if (!room->used)
	{
		room->used = 1;
		connect = room->connect;
		while (connect)
		{
			receveid = get_smaller((t_room *)connect->content, pos + 1);
			if (!depth)
				depth = receveid;
			else if (receveid)
				depth = ft_min(receveid, depth);
			connect = connect->next;
		}
		room->used = 0;
	}
	return (depth);
}

static int		create_road(t_road *n_road, t_room *room, int depth)
{
	t_ld	*connect;

	if (room->type == -1 && !depth)
	{
		ft_ld_pushfront(&n_road->step, room);
		return (1);
	}
	if (!depth)
		return (0);
	if (!room->used)
	{
		room->used = 1;
		connect = room->connect;
		while (connect)
		{
			if (create_road(n_road, (t_room *)connect->content, depth - 1))
			{
				ft_ld_pushfront(&n_road->step, room);
				return (1);
			}
			connect = connect->next;
		}
		room->used = 0;
	}
	return (0);
}

static t_road	*init_road(t_room *start, int len)
{
	t_road	*new_road;

	if (!(new_road = (t_road *)malloc(sizeof(t_road))))
		malloc_error("road");
	new_road->size = len;
	new_road->step = NULL;
	create_road(new_road, start, len);
	return (new_road);
}

void			set_road(t_lem *lem)
{
	t_room	*start;
	int		len;
	int		possible_start;

	start = get_room_type(lem->room, 1);
	possible_start = ft_ld_size(start->connect);
	while (possible_start)
	{
		start->used = 0;
		len = get_smaller(start, 0);
		if (len)
			ft_ld_pushfront(&lem->road, init_road(start, len));
		--possible_start;
	}
	ft_ld_reverse(&lem->road);
}
