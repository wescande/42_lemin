/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:12:42 by wescande          #+#    #+#             */
/*   Updated: 2017/02/24 14:17:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

static int		import_image(t_visualize *vi)
{
	if (!(vi->ground.img_ptr = mlx_xpm_file_to_image(vi->mlx,
			"./dir_visualizer/ants/sol.xpm",
			&vi->ground.width, &vi->ground.height)))
		return (1);
	vi->ground.data = mlx_get_data_addr(vi->ground.img_ptr, &vi->ground.bpp,
									&vi->ground.size, &vi->ground.endian);
	if (!(vi->ant0.img_ptr = mlx_xpm_file_to_image(vi->mlx,
			"./dir_visualizer/ants/ant0.xpm",
			&vi->ant0.width, &vi->ant0.height)))
		return (1);
	vi->ant0.data = mlx_get_data_addr(vi->ant0.img_ptr, &vi->ant0.bpp,
									&vi->ant0.size, &vi->ant0.endian);
	if (!(vi->ant1.img_ptr = mlx_xpm_file_to_image(vi->mlx,
			"./dir_visualizer/ants/ant1.xpm",
			&vi->ant1.width, &vi->ant1.height)))
		return (1);
	vi->ant1.data = mlx_get_data_addr(vi->ant1.img_ptr, &vi->ant1.bpp,
									&vi->ant1.size, &vi->ant1.endian);
	if (!(vi->ant2.img_ptr = mlx_xpm_file_to_image(vi->mlx,
			"./dir_visualizer/ants/ant2.xpm",
			&vi->ant2.width, &vi->ant2.height)))
		return (1);
	vi->ant2.data = mlx_get_data_addr(vi->ant2.img_ptr, &vi->ant2.bpp,
									&vi->ant2.size, &vi->ant2.endian);
	return (0);
}

static int		create_win(t_visualize *vi, int max_x, int max_y)
{
	vi->mlxsize.x = 2300;
	vi->mlxsize.y = 1200;
	vi->ratio.x = (vi->mlxsize.x - 100) / max_x;
	vi->ratio.y = (vi->mlxsize.y - 150) / max_y;
	vi->mlx = mlx_init();
	vi->win = mlx_new_window(vi->mlx, vi->mlxsize.x,
			vi->mlxsize.y, "VISUAL turn");
	vi->img.img_ptr = mlx_new_image(vi->mlx, vi->mlxsize.x, vi->mlxsize.y);
	vi->img.data = mlx_get_data_addr(vi->img.img_ptr, &vi->img.bpp,
									&vi->img.size, &vi->img.endian);
	vi->img.width = vi->mlxsize.x;
	vi->img.height = vi->mlxsize.y;
	if (import_image(vi))
	{
		ft_dprintf(2, "{red}visualize: error while import xpm\n{eoc}");
		return (1);
	}
//	mlx_do_key_autorepeatoff(vi->mlx);
	mlx_hook(vi->win, 2, (1L << 0), &my_key_hook, vi);
	mlx_expose_hook(vi->win, &my_expose_hook, vi);
	return (0);
}

int				get_max_size(t_ld *ld, int height)
{
	int len;
	int len2;

	len = 1;
	if (height)
		while (ld)
		{
			len2 = ((t_room *)ld->content)->pos.y;
			if (len2 > len)
				len = len2;
			ld = ld->next;
		}
	else
		while (ld)
		{
			len2 = ((t_room *)ld->content)->pos.x;
			if (len2 > len)
				len = len2;
			ld = ld->next;
		}
	return (len);
}

void			manage_coor(t_ld *ld, t_c_2d ratio)
{
	while (ld)
	{
		((t_room *)ld->content)->pos.x *= ratio.x;
		((t_room *)ld->content)->pos.y *= ratio.y;
		((t_room *)ld->content)->pos.x += 50;
		((t_room *)ld->content)->pos.y += 100;
		ld = ld->next;
	}
}

int				main(int argc, char **argv)
{
	t_visualize		vi;
	t_lem			lem;

	(void)argv;
	lem = (t_lem){0, NULL, NULL, NULL, (t_turn){0, NULL}};
	if (argc > 1)
		ft_dprintf(2, "usage: %s\n", argv[0]);
	if (lem_in_input(&lem))
	{
		ft_dprintf(2, "{red}visualize: initializing probleme\n{eoc}");
		return (1);
	}
	set_run(&lem);
	vi.lem = &lem;
	vi.speed = 20;
	if (create_win(&vi, get_max_size(lem.room, 0), get_max_size(lem.room, 1)))
		return (1);
	manage_coor(lem.room, vi.ratio);
	calcul_image(&lem, &vi);
	mlx_loop(vi.mlx);
	return (0);
}
