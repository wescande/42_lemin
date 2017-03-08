/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:38:03 by wescande          #+#    #+#             */
/*   Updated: 2017/01/03 14:52:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		link_exist(t_room *room, t_room *lk_room)
{
	t_ld	*cur;

	cur = room->connect;
	while (cur)
	{
		if ((t_room *)cur->content == lk_room)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static int		check_add_link(t_lem *lem, char *line)
{
	char	**split;
	int		ret;
	t_room	*room1;
	t_room	*room2;

	split = ft_strsplit(line, '-');
	ret = ft_tablen(split) != 2;
	if (!ret && (!(room1 = get_room(lem, split[0]))
		|| !(room2 = get_room(lem, split[1])) || room1 == room2))
		ret = 1;
	if (!ret && link_exist(room1, room2))
	{
		ft_dprintf(2, "lem_in: {red}Multiple link detected. (%s - %s)\n{eoc}",
			split[0], split[1]);
		ret = 1;
	}
	if (!ret)
	{
		ft_ld_pushfront(&room1->connect, room2);
		ft_ld_pushfront(&room2->connect, room1);
	}
	ft_tabdel(&split);
	return (ret);
}

void			set_link(t_lem *lem, char **line)
{
	if (check_add_link(lem, *line))
		return ;
	ft_ld_pushfront(&lem->data, *line);
	while (get_next_line(0, line) > 0)
	{
		if (*line[0] != '#' && check_add_link(lem, *line))
			return ;
		ft_ld_pushfront(&lem->data, *line);
	}
}
