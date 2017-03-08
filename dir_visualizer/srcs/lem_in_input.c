/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:26:56 by wescande          #+#    #+#             */
/*   Updated: 2017/01/03 15:18:48 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

static int		get_nb_ants(t_lem *lem, char **line)
{
	int neg;

	if (!(get_next_line(0, line) > 0))
		return (1);
	lem->ants = ft_atoli_base(*line, 10);
	neg = 0;
	if (lem->ants < 0 && lem->ants > -2147483648 && (neg = 1))
		lem->ants = -lem->ants;
	else if (lem->ants <= 0 || lem->ants > 21474836483647)
	{
		ft_strdel(line);
		return (1);
	}
	if (!ft_strisdigit(*line + neg))
	{
		ft_strdel(line);
		return (1);
	}
	ft_strdel(line);
	return (0);
}

int				lem_in_input(t_lem *lem)
{
	char	*line;

	line = NULL;
	if (get_nb_ants(lem, &line))
		return (1);
	if (set_room(lem, &line))
	{
		ft_ld_clear(&lem->room, &ft_memdel);
		return (1);
	}
	set_link(lem, &line);
	set_road(lem);
	return (0);
}
