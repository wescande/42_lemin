/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 04:12:50 by wescande          #+#    #+#             */
/*   Updated: 2016/12/29 12:35:00 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

t_turn		*init_turn(int index, char **tabsplit)
{
	t_turn		*n_turn;
	char		**split;
	int			i;
	int			len;

	if (!(n_turn = (t_turn *)malloc(sizeof(t_turn))))
		malloc_error("turn");
	n_turn->num = index;
	n_turn->move = NULL;
	len = ft_tablen(tabsplit);
	i = -1;
	while (++i < len)
	{
		split = ft_strsplit(tabsplit[i] + 1, '-');
		ft_ld_pushfront(&n_turn->move, split);
	}
	return (n_turn);
}

void		set_turn(t_lem *lem, char **line)
{
	char	**split;
	int		i;

	ft_strdel(line);
	i = 0;
	while (get_next_line(0, line))
	{
		split = ft_strsplit(*line, ' ');
		ft_ld_pushfront(&lem->turn.move, init_turn(i, split));
		ft_tabdel(&split);
		ft_strdel(line);
		++i;
	}
	ft_ld_reverse(&lem->turn.move);
}
