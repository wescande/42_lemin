/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:17:36 by wescande          #+#    #+#             */
/*   Updated: 2017/01/03 14:38:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZE_H
# define VISUALIZE_H

# if defined __APPLE__
#  include "my_key_apple.h"
# endif
# if defined __linux__
#  include "my_key_linux.h"
#  include <X11/Xlib.h>
# endif

# include <mlx.h>
# include <../libft/includes/libft.h>

typedef struct	s_c_2d
{
	int		x;
	int		y;
}				t_c_2d;

typedef struct	s_room
{
	char		*name;
	t_c_2d		pos;
	long		ants;
	int			type;
	int			used;
	t_ld		*connect;
}				t_room;

typedef struct	s_show
{
	int			num;
	t_c_2d		coor;
	t_c_2d		desti;
}				t_show;

typedef struct	s_turn
{
	int			num;
	t_ld		*move;
}				t_turn;

typedef struct	s_road
{
	int			size;
	t_ld		*step;
}				t_road;

typedef struct	s_run
{
	int			num;
	int			started;
	t_ld		*step;
}				t_run;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct	s_point
{
	t_c_2d	c_2d;
	t_color	color;
}				t_point;

typedef struct	s_image
{
	void	*img_ptr;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size;
	int		endian;
}				t_image;

typedef struct	s_lem
{
	long		ants;
	t_ld		*room;
	t_ld		*road;
	t_ld		*running_ant;
	t_turn		turn;
}				t_lem;

typedef struct	s_visualize
{
	void				*mlx;
	void				*win;
	t_c_2d				mlxsize;
	t_image				img;
	t_image				ground;
	t_image				ant0;
	t_image				ant1;
	t_image				ant2;
	t_lem				*lem;
	t_c_2d				ratio;
	int					speed;
}				t_visualize;

void			set_pixel_to_image(t_image *img, int x, int y, t_color col);
void			set_circle_to_image(t_image *img, t_c_2d start,
									int radius, t_color color);
void			set_line_to_image(t_image *img, t_point start, t_point end);

/*
** Lem-in
*/
int				lem_in_input(t_lem *lem);
int				set_room(t_lem *lem, char **line);
int				room_exist(t_lem *lem, char *name);
void			set_link(t_lem *lem, char **line);
void			set_turn(t_lem *lem, char **line);
t_room			*get_room(t_lem *lem, char *name);
t_room			*get_room_type(t_ld *lst, int type);
void			lem_in_exit(t_lem *lem);
void			malloc_error(char *str);
void			set_road(t_lem *lem);
void			set_run(t_lem *lem);
void			manage_ants(t_lem *lem, int next);

/*
** Draw
*/
void			calcul_image(t_lem *lem, t_visualize *vi);

/*
** Hook
*/
int				my_expose_hook(t_visualize *vi);
int				my_key_hook(int key, t_visualize *vi);

#endif
