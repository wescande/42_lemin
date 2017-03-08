/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 00:40:54 by wescande          #+#    #+#             */
/*   Updated: 2017/01/03 14:37:50 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"

static t_color	color_gradient(t_point p0, t_point p1)
{
	t_color	color;

	color = p0.color;
	color.r += (p1.color.r - p0.color.r) /
	(ft_abs(p1.c_2d.x - p0.c_2d.x) + ft_abs(p1.c_2d.y - p0.c_2d.y));
	color.g += (p1.color.g - p0.color.g) /
	(ft_abs(p1.c_2d.x - p0.c_2d.x) + ft_abs(p1.c_2d.y - p0.c_2d.y));
	color.b += (p1.color.b - p0.color.b) /
	(ft_abs(p1.c_2d.x - p0.c_2d.x) + ft_abs(p1.c_2d.y - p0.c_2d.y));
	return (color);
}

static int		in_img(t_image *img, t_point p0, t_point p1)
{
	if (p0.c_2d.x < 0 && p1.c_2d.x < 0)
		return (0);
	if (p0.c_2d.y < 0 && p1.c_2d.y < 0)
		return (0);
	if (p0.c_2d.x > img->width && p1.c_2d.x > img->width)
		return (0);
	if (p0.c_2d.y > img->height && p1.c_2d.y > img->height)
		return (0);
	if (p0.c_2d.x == p1.c_2d.x && p0.c_2d.y == p1.c_2d.y)
		return (0);
	return (1);
}

void			set_pixel_to_image(t_image *img, int x, int y, t_color color)
{
	int		pos;

	if (x > 0 && x < img->width
		&& y > 0 && y < img->height)
	{
		pos = x * img->bpp / 8 + (y * img->size);
		img->data[pos] = color.b;
		img->data[pos + 1] = color.g;
		img->data[pos + 2] = color.r;
	}
}

void			set_circle_to_image(t_image *img, t_c_2d start,
								int radius, t_color color)
{
	int	x;
	int	y;

	x = ft_max(start.x - radius, 0);
	while (x < ft_min(start.x + radius, img->width))
	{
		y = ft_max(start.y - radius, 0);
		while (y < ft_min(start.y + radius, img->height))
		{
			if ((x - start.x) * (x - start.x) + (y - start.y) * (y - start.y)
				<= radius * radius)
				set_pixel_to_image(img, x, y, color);
			++y;
		}
		++x;
	}
}

void			set_line_to_image(t_image *img, t_point p0, t_point p1)
{
	int		delta[2];
	int		move[2];
	int		err[2];

	delta[0] = ft_abs(p1.c_2d.x - p0.c_2d.x);
	delta[1] = ft_abs(p1.c_2d.y - p0.c_2d.y);
	move[0] = p0.c_2d.x < p1.c_2d.x ? 1 : -1;
	move[1] = p0.c_2d.y < p1.c_2d.y ? 1 : -1;
	err[0] = (delta[0] > delta[1] ? delta[0] : -delta[1]) / 2;
	while (in_img(img, p0, p1))
	{
		set_pixel_to_image(img, p0.c_2d.x, p0.c_2d.y, p0.color);
		err[1] = err[0];
		p0.color = color_gradient(p0, p1);
		if (err[1] > -delta[0] && ((err[0] -= delta[1]) || 1))
			p0.c_2d.x += move[0];
		if (err[1] < delta[1])
		{
			err[0] += delta[0];
			p0.c_2d.y += move[1];
		}
	}
	set_pixel_to_image(img, p0.c_2d.x, p0.c_2d.y, p0.color);
}
