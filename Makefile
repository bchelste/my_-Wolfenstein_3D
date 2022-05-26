# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 12:25:27 by bchelste          #+#    #+#              #
#    Updated: 2021/03/25 01:36:10 by bchelste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

SRCS		=	./utils/ft_atoi.c \
				./utils/ft_lstadd_back.c \
				./utils/ft_lstadd_front.c \
				./utils/ft_lstdelone.c \
				./utils/ft_lstnew.c \
				./utils/ft_lstsize.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_strchr.c \
				./utils/ft_strdup.c \
				./utils/ft_strjoin.c \
				./utils/ft_strlen.c \
				./utils/ft_substr.c \
				./utils/get_next_line.c \
				./srcs/main.c \
				./srcs/ft_functions.c \
				./srcs/ft_check_argv.c \
				./srcs/ft_init_structs.c \
				./srcs/ft_parser_inf.c \
				./srcs/ft_get_text_path.c \
				./srcs/ft_get_inf.c \
				./srcs/ft_check_inf.c \
				./srcs/ft_check_ff_map.c \
				./srcs/ft_cub3d.c \
				./srcs/ft_dda.c \
				./srcs/ft_game.c \
				./srcs/ft_keys.c \
				./srcs/ft_plr_move.c \
				./srcs/ft_plr_rot.c \
				./srcs/ft_screenshot.c \
				./srcs/ft_sprites.c \
				./srcs/ft_sprites_arr.c \
				./srcs/ft_text_to_img.c \
				./srcs/ft_free_exit.c \
				./srcs/ft_wall_text.c

OBJS		= $(SRCS:.c=.o)

MLX_A		= libmlx.a

MLX_DIR		= mlx_linux

INC 		= -Isrcs -I$(MLX_DIR)


MLX_LIBS	= -lXext -lX11 -lm

OPTFLAGS	= -O3

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MLX_DIR)/$(MLX_A) -o $(NAME) $(MLX_LIBS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

%.o: %.c
			$(CC) $(CFLAGS) $(INC) $(OPTFLAGS) -c $< -o $@

.PHONY:     all clean fclean re