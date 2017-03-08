#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2016/12/24 02:23:45 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME		=	visualizer

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -Ofast

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

MLX_DIR		=	minilibx/
MLX_LIB		=	$(MLX_DIR)libmlx.a
MLX_INC		=	$(MLX_DIR)includes/

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

UNAME		=	$(shell uname)

ifeq ($(UNAME), Darwin)
LIBX		=	-lmlx -framework OpenGl -framework Appkit -I/Users/wescande/.brew/include/
endif

ifeq ($(UNAME), Linux)
LIBX		=	-I$(MLX_INC) $(MLX_LIB) -lm -lX11 -lXext
endif

SRC_BASE	=	\
ft_visualize.c\
lem_in_exit.c\
lem_in_input.c\
lem_in_link.c\
lem_in_output.c\
lem_in_road.c\
lem_in_room.c\
lem_in_run.c\
lem_in_turn.c\
visualize_calcul.c\
visualize_hook.c\
visualize_output.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all :			$(NAME)

$(NAME):		$(MLX_LIB) $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) $(LIBFT_LIB) \
		$(LIBX) \
		$(FLAGS)
	@echo "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K"

ifeq ($(UNAME), Darwin)
$(MLX_LIB):
endif

ifeq ($(UNAME), Linux)
$(MLX_LIB):
		@make -C $(MLX_DIR)
endif

$(LIBFT_LIB):
	@make -j -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) -MMD -c $< -o $@ \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		-I $(MLX_INC) \
		-I/Users/wescande/.brew/include/ \
		$(FLAGS)
	@printf "\r\033[38;5;11m⌛ MAKE %s     plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@echo "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K"

ifeq ($(UNAME), Darwin)
cleanlib:
	@make -C $(LIBFT_DIR) clean
endif

ifeq ($(UNAME), Linux)
cleanlib:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
endif

fclean:			clean fcleanlib
	@rm -f $(NAME)
	@echo "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K"

ifeq ($(UNAME), Darwin)
fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean
endif

ifeq ($(UNAME), Linux)
fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) fclean
endif

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
