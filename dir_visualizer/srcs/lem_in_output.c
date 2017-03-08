/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 22:52:14 by wescande          #+#    #+#             */
/*   Updated: 2016/12/31 15:40:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

void	malloc_error(char *str)
{
	ft_dprintf(2, "lem-in: {red}Error while malloc: %s{eoc}", str);
	exit(1);
}

t_show	*init_move(int num, t_c_2d start, t_c_2d end)
{
	t_show	*n_show;

	if (!(n_show = (t_show *)malloc(sizeof(t_show))))
		malloc_error("turn");
	n_show->num = num;
	n_show->coor = start;
	n_show->desti = end;
	return (n_show);
}

t_ld	*move_ants_right(t_ld *lst, t_room *end)
{
	t_run	*run;
	t_c_2d	coor_start;
	t_c_2d	coor_end;
	t_ld	*turn;

	turn = NULL;
	while (lst && (run = (t_run *)lst->content))
	{
		if (!run->started && (!((t_room *)run->step->next->content)->ants
					|| ((t_room *)run->step->next->content)->type == -1))
			run->started = 1;
		if (run->started == 1)
		{
			coor_start = ((t_room *)run->step->content)->pos;
			--((t_room *)run->step->content)->ants;
			run->step = run->step->next;
			if ((t_room *)run->step->content == end)
				run->started = -1;
			coor_end = ((t_room *)run->step->content)->pos;
			++((t_room *)run->step->content)->ants;
			ft_ld_pushfront(&turn, init_move(run->num, coor_start, coor_end));
		}
		lst = lst->next;
	}
	return (turn);
}

t_ld	*move_ants_left(t_ld *lst, t_room *end)
{
	t_run	*run;
	t_c_2d	coor_start;
	t_c_2d	coor_end;
	t_ld	*turn;

	turn = NULL;
	while (lst && (run = (t_run *)lst->content))
	{
		if (run->started == -1 && (!((t_room *)run->step->prev->content)->ants
					|| ((t_room *)run->step->prev->content)->type == 1))
			run->started = 1;
		if (run->started == 1)
		{
			coor_start = ((t_room *)run->step->content)->pos;
			--((t_room *)run->step->content)->ants;
			run->step = run->step->prev;
			if ((t_room *)run->step->content == end)
				run->started = 0;
			coor_end = ((t_room *)run->step->content)->pos;
			++((t_room *)run->step->content)->ants;
			ft_ld_pushfront(&turn, init_move(run->num, coor_start, coor_end));
		}
		lst = lst->prev;
	}
	return (turn);
}

void	manage_ants(t_lem *lem, int next)
{
	ft_ld_clear(&lem->turn.move, NULL);
	if (next)
	{
		lem->turn.move = move_ants_right(lem->running_ant,
				get_room_type(lem->room, -1));
		if (lem->turn.move)
			++lem->turn.num;
	}
	else
	{
		lem->turn.move = move_ants_left(ft_ld_back(lem->running_ant),
				get_room_type(lem->room, 1));
		if (lem->turn.move)
			--lem->turn.num;
	}
}
