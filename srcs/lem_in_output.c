/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 22:52:14 by wescande          #+#    #+#             */
/*   Updated: 2016/12/30 10:46:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	malloc_error(char *str)
{
	ft_dprintf(2, "lem-in: {red}Error while malloc: %s{eoc}", str);
	exit(1);
}

int		move_ants(t_ld *lst, t_room *end)
{
	t_run	*run;
	int		move;

	move = 0;
	while (lst)
	{
		run = (t_run *)lst->content;
		if (!run->started && (!((t_room *)run->step->next->content)->ants
				|| ((t_room *)run->step->next->content)->type == -1))
			run->started = 1;
		if (run->started == 1)
		{
			--((t_room *)run->step->content)->ants;
			run->step = run->step->next;
			if ((t_room *)run->step->content == end)
				run->started = -1;
			ft_printf("%sL%d-%s", move ? " " : "", run->num,
					((t_room *)run->step->content)->name);
			++((t_room *)run->step->content)->ants;
			move = 1;
		}
		lst = lst->next;
	}
	return (move);
}

void	manage_ants(t_lem *lem)
{
	int		not_finished;
	t_room	*room_end;

	not_finished = 1;
	room_end = get_room_type(lem->room, -1);
	while (not_finished)
	{
		not_finished = 0;
		if (move_ants(lem->running_ant, room_end))
		{
			not_finished = 1;
			ft_printf("\n");
		}
	}
}

int		lem_in_output(t_lem *lem)
{
	t_ld	*data;

	ft_ld_reverse(&lem->data);
	data = lem->data;
	while (data)
	{
		ft_printf("%s\n", data->content);
		data = data->next;
	}
	ft_printf("\n");
	manage_ants(lem);
	return (0);
}
