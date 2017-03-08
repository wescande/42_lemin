/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:08:47 by wescande          #+#    #+#             */
/*   Updated: 2017/01/03 14:20:30 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_run			*init_run(int ant_num, t_ld *step)
{
	t_run	*n_run;

	if (!(n_run = (t_run *)malloc(sizeof(t_run))))
		malloc_error("run");
	n_run->num = ant_num;
	n_run->started = 0;
	n_run->step = step;
	return (n_run);
}

int				ft_ld_pos(t_ld *all, t_ld *alone)
{
	int		pos;

	pos = 0;
	if (!all || !alone)
		return (pos);
	while (all && all != alone)
	{
		++pos;
		all = all->next;
	}
	if (!all)
		return (0);
	return (pos);
}

static int		pass_it(t_ld *block, t_ld *cur, int ant_rest)
{
	int		delta;
	int		my_pos;
	t_ld	*pre;

	if (!cur)
		return (1);
	pre = cur->prev;
	my_pos = ft_ld_pos(block, cur);
	while (block && pre && cur)
	{
		delta = ((t_road *)cur->content)->size - ((t_road *)pre->content)->size;
		if (!delta)
			return (0);
		if ((!((ant_rest - ft_ld_pos(block, pre)) / my_pos)
			&& delta > (ant_rest - ft_ld_pos(block, pre))) ||
			((((ant_rest - ft_ld_pos(block, pre)) / my_pos)
			&& delta > (ant_rest - ft_ld_pos(block, pre)) / my_pos)))
			return (1);
		pre = pre->prev;
	}
	return (0);
}

void			set_run(t_lem *lem)
{
	int		i;
	t_ld	*road;
	int		pass;

	i = 1;
	while (i <= lem->ants)
	{
		road = lem->road;
		pass = 0;
		while (road && i <= lem->ants && !pass)
		{
			ft_ld_pushfront(&lem->running_ant,
					init_run(i, ((t_road *)road->content)->step));
			road = road->next;
			pass = pass_it(lem->road, road, lem->ants - i);
			++i;
		}
	}
	ft_ld_reverse(&lem->running_ant);
}
