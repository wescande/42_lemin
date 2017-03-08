/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:17:41 by wescande          #+#    #+#             */
/*   Updated: 2016/12/29 01:45:15 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			usage(char *str)
{
	ft_dprintf(2, "usage: %s\n", str);
}

int				main(int argc, char **argv)
{
	t_lem	lem;

	lem = (t_lem){0, NULL, NULL, NULL, NULL};
	if (argc > 1)
		usage(argv[0]);
	if (lem_in_input(&lem))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	set_run(&lem);
	lem_in_output(&lem);
	lem_in_exit(&lem);
	return (0);
}
