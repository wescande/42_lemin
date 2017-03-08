#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2016/12/24 02:01:04 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#
INC=/usr/include
HT=Linux
DOCP=do_cp

NAME		=	libmlx.a

CC			=	gcc
FLAGS		=	-O3 -w

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	= \
mlx_new_window.c\
mlx_destroy_window.c\
mlx_flush_event.c\
mlx_put_image_to_window.c\
mlx_int_anti_resize_win.c\
mlx_int_get_visual.c\
mlx_int_do_nothing.c\
mlx_hook.c\
mlx_loop.c\
mlx_get_data_addr.c\
mlx_clear_window.c\
mlx_int_wait_first_expose.c\
mlx_expose_hook.c\
mlx_xpm.c\
mlx_string_put.c\
mlx_pixel_put.c\
mlx_destroy_image.c\
mlx_rgb.c\
mlx_get_color_value.c\
mlx_loop_hook.c\
mlx_init.c\
mlx_int_set_win_event_mask.c\
mlx_mouse_hook.c\
mlx_int_param_event.c\
mlx_new_image.c\
mlx_int_str_to_wordtab.c\
mlx_key_hook.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all	: do_configure

do_configure	:
	@./configure

clean	:
	@./configure clean

fclean	:
	@./configure fclean

re	: clean all

lib :
	@$(MAKE) -j $(NAME)

$(NAME) :		$(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) -MMD -c $< -o $@\
		-I$(INC_DIR) \
		-I$(INC) \
		$(FLAGS)
	@printf "\r\033[38;5;11m⌛ MAKE %s     plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

libclean :
	@rm -rf $(OBJ_DIR)
	@echo "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K"

libfclean :		clean
	@rm -rf $(NAME)
	@echo "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K"

.PHONY :		fclean clean re lib libclean libfclean

-include $(OBJS:.o=.d)
