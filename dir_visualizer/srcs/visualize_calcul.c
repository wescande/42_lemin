/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_calcul.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 05:25:59 by wescande          #+#    #+#             */
/*   Updated: 2016/12/30 16:23:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

void	draw_link(t_visualize *vi, t_c_2d origin, t_c_2d desti)
{
	t_c_2d		delta;
	t_color		color_or;
	t_color		color_dest;

	delta = (t_c_2d){0, 0};
	color_or = (t_color){244, 164, 96};
	color_dest = (t_color){255, 248, 220};
	origin = (t_c_2d){origin.x - 15, origin.y - 15};
	desti = (t_c_2d){(desti.x + origin.x) / 2, (desti.y + origin.y) / 2};
	while (++delta.x < 31)
	{
		delta.y = 0;
		while (++delta.y < 31)
		{
			set_line_to_image(&vi->img, (t_point){origin, color_or},
										(t_point){desti, color_dest});
			++origin.y;
		}
		origin.y -= 30;
		++origin.x;
	}
}

void	image_to_image(t_image *dst, t_image *src, int fill)
{
	t_c_2d	c_dst;
	t_c_2d	c_src;
	t_c_2d	rev;

	c_dst = (t_c_2d){0, 0};
	c_src = (t_c_2d){0, 0};
	rev = (t_c_2d){0, 0};
	while (c_dst.y < dst->height && !(c_dst.x = 0))
	{
		while (c_dst.x < dst->width)
		{
			ft_memcpy(dst->data + c_dst.y * 4 * dst->width + c_dst.x * 4,
					src->data + c_src.y * 4 * src->width + c_src.x * 4, 4);
			c_src.x += rev.x % 2 ? -1 : 1;
			if ((c_src.x == src->width - 1 || !c_src.x) && ++rev.x && !fill)
				c_dst.x = dst->width;
			++c_dst.x;
		}
		rev.x = 0;
		c_src.x = 0;
		c_src.y += rev.y % 2 ? -1 : 1;
		if ((c_src.y == src->height - 1 || !c_src.y) && ++rev.y && !fill)
			c_dst.y = dst->height;
		++c_dst.y;
	}
}

void	calcul_image(t_lem *lem, t_visualize *vi)
{
	t_ld	*cur;
	t_ld	*con;

	image_to_image(&vi->img, &vi->ground, 1);
	cur = lem->room;
	while (cur)
	{
		con = ((t_room *)cur->content)->connect;
		while (con)
		{
			draw_link(vi, (t_c_2d){((t_room *)cur->content)->pos.x,
				((t_room *)cur->content)->pos.y},
				(t_c_2d){((t_room *)con->content)->pos.x,
				((t_room *)con->content)->pos.y});
			con = con->next;
		}
		cur = cur->next;
	}
	cur = lem->room;
	while (cur)
	{
		set_circle_to_image(&vi->img, (t_c_2d){((t_room *)cur->content)->pos.x,
				((t_room *)cur->content)->pos.y}, 22, (t_color){244, 164, 96});
		cur = cur->next;
	}
}
