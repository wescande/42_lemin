/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:41:30 by wescande          #+#    #+#             */
/*   Updated: 2017/01/03 14:41:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

void			move_coor(t_c_2d *c0, t_c_2d c1, int speed)
{
	int		delta[2];
	int		move[2];
	int		err[2];
	int		loop;

	loop = -1;
	delta[0] = ft_abs(c1.x - c0->x);
	delta[1] = ft_abs(c1.y - c0->y);
	move[0] = c0->x < c1.x ? 1 : -1;
	move[1] = c0->y < c1.y ? 1 : -1;
	err[0] = (delta[0] > delta[1] ? delta[0] : -delta[1]) / 2;
	while (++loop < speed && (c0->x != c1.x || c0->y != c1.y))
	{
		err[1] = err[0];
		if (err[1] > -delta[0] && ((err[0] -= delta[1]) || 1))
			c0->x += move[0];
		if (err[1] < delta[1])
		{
			err[0] += delta[0];
			c0->y += move[1];
		}
	}
}

int				expose_ants(t_visualize *vi, t_ld *cur)
{
	int		moving;
	t_show	*cur_coor;

	moving = 0;
	while (cur && (cur_coor = (t_show *)cur->content))
	{
		if (ft_abs(cur_coor->coor.x - cur_coor->desti.x) > 5
			|| ft_abs(cur_coor->coor.y - cur_coor->desti.y) > 5)
		{
			moving = 1;
			move_coor(&cur_coor->coor, cur_coor->desti, vi->speed);
		}
		if (cur_coor->num % 3 == 1)
			mlx_put_image_to_window(vi->mlx, vi->win, vi->ant1.img_ptr,
	cur_coor->coor.x - vi->ant1.width / 2, cur_coor->coor.y - vi->ant1.height);
		else if (cur_coor->num % 3 == 2)
			mlx_put_image_to_window(vi->mlx, vi->win, vi->ant2.img_ptr,
	cur_coor->coor.x - vi->ant2.width / 2, cur_coor->coor.y - vi->ant2.height);
		else
			mlx_put_image_to_window(vi->mlx, vi->win, vi->ant0.img_ptr,
	cur_coor->coor.x - vi->ant0.width / 2, cur_coor->coor.y - vi->ant0.height);
		cur = cur->next;
	}
	return (moving);
}

int				my_expose_hook(t_visualize *vi)
{
	char	*str;
	int		moving;

	ft_asprintf(&str, "Turn num %d at speed %d", vi->lem->turn.num, vi->speed);
	moving = 1;
	mlx_put_image_to_window(vi->mlx, vi->win, vi->img.img_ptr, 0, 0);
	mlx_string_put(vi->mlx, vi->win, 0, 5, 0x00FFFFFF, str);
	while (moving)
	{
		mlx_put_image_to_window(vi->mlx, vi->win, vi->img.img_ptr, 0, 0);
		mlx_string_put(vi->mlx, vi->win, 0, 5, 0x00FFFFFF, str);
		moving = expose_ants(vi, vi->lem->turn.move);
		mlx_do_sync(vi->mlx);
	}
	ft_strdel(&str);
	return (0);
}

int				my_key_hook(int key, t_visualize *vi)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_RIGHT || key == K_LEFT)
	{
		manage_ants(vi->lem, key == K_RIGHT);
	}
	else if (key == K_PAD_ADD)
		++vi->speed;
	else if (key == K_PAD_SUB && vi->speed > 1)
		--vi->speed;
	my_expose_hook(vi);
	return (0);
}
