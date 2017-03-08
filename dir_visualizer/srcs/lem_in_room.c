/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:26:56 by wescande          #+#    #+#             */
/*   Updated: 2017/01/03 15:01:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

t_room					*get_room(t_lem *lem, char *name)
{
	t_room	*my_room;
	t_ld	*room_lst;

	my_room = NULL;
	room_lst = lem->room;
	while (room_lst && !my_room)
	{
		if (!ft_strcmp(((t_room *)room_lst->content)->name, name))
			my_room = (t_room *)room_lst->content;
		room_lst = room_lst->next;
	}
	return (my_room);
}

static int				check_cmd(char *line, int type)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	if (!ft_strcmp(line, "##end"))
		return (-1);
	return (type);
}

static int				nb_room_type(t_ld *ld, int type)
{
	int		count;

	count = 0;
	while (ld)
	{
		if (((t_room *)ld->content)->type == type)
			++count;
		ld = ld->next;
	}
	return (count);
}

static int				check_add_room(t_lem *lem, char *line, int next)
{
	char	**split;
	int		ret;
	t_room	*n_room;

	split = ft_strsplit(line, ' ');
	ret = (ft_tablen(split) != 3);
	if (!ret && (split[0][0] == '#' || split[0][0] == 'L' ||
		(!ft_strisdigit(split[1]) || !ft_strisdigit(split[2]))))
		ret = 1;
	if (!ret && get_room(lem, split[0]))
		ret = 1;
	if (!ret)
	{
		if (!(n_room = (t_room *)malloc(sizeof(t_room))))
			malloc_error("room");
		*n_room = (t_room) {ft_strdup(split[0]),
			(t_c_2d){ft_atoli_base(split[1], 10), ft_atoli_base(split[2], 10)},
			next == 1 ? lem->ants : 0, next, 0, NULL};
		ft_ld_pushfront(&lem->room, n_room);
	}
	ft_tabdel(&split);
	return (ret);
}

int						set_room(t_lem *lem, char **line)
{
	int		next;

	next = 0;
	while (get_next_line(0, line) > 0)
	{
		if ((*line)[0] == '#')
		{
			next = check_cmd(*line, next);
			ft_strdel(line);
		}
		else if (!check_add_room(lem, *line, next))
		{
			next = 0;
			ft_strdel(line);
		}
		else
			break ;
	}
	if (next || nb_room_type(lem->room, 1) != 1
			|| nb_room_type(lem->room, -1) != 1)
		return (1);
	return (0);
}
