/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:15:34 by wescande          #+#    #+#             */
/*   Updated: 2016/12/30 10:47:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

/*
** Type of room could be:
**      0  for normal
**      1  for start
**     -1  for end
*/

typedef struct	s_room
{
	char		*name;
	long		ants;
	int			type;
	int			used;
	t_ld		*connect;
}				t_room;

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

typedef struct	s_lem
{
	long		ants;
	t_ld		*room;
	t_ld		*road;
	t_ld		*data;
	t_ld		*running_ant;
}				t_lem;

/*
** Input
*/
int				lem_in_input(t_lem *lem);
int				set_room(t_lem *lem, char **line);
int				room_exist(t_lem *lem, char *name);
void			set_link(t_lem *lem, char **line);
t_room			*get_room(t_lem *lem, char *name);
t_room			*get_room_type(t_ld *lst, int type);

/*
** manage road & run
*/
void			set_road(t_lem *lem);
void			set_run(t_lem *lem);

/*
** Output
*/
int				lem_in_output(t_lem *lem);
void			malloc_error(char *str);
void			lem_in_exit(t_lem *lem);

#endif
