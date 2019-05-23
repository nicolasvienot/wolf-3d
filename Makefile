# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 17:31:14 by nvienot           #+#    #+#              #
#    Updated: 2019/05/22 18:55:57 by nvienot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d

SRCS	=	sources/main.c \
			sources/init.c \
			sources/multithreading.c \
			sources/calc.c \
			sources/test_walls.c \
			sources/fps.c \
			sources/print.c \
			sources/parser.c \
			sources/parser2.c \
			sources/draw.c \
			sources/sdl_event.c \
			sources/sdl_event2.c \
			sources/sdl_event3.c \
			sources/textures.c \
			sources/anim.c \
			sources/minimap.c \
			sources/minimap2.c \
			sources/loop.c \
			sources/exit.c \
			sources/utils.c

CC		=	gcc

INCL	=	-I libraries/libft/ -I includes/ \
			-I ./frameworks/SDL2.framework/Headers \
			-I ./frameworks/SDL2_ttf.framework/Headers \
			-I ./frameworks/SDL2_image.framework/Headers \
			-I ./frameworks/SDL2_mixer.framework/Headers

INCL_NORM	=	libraries/libft/ includes/

FLAGS	=	-Wall -Wextra -Werror -O3

OBJS	=	$(SRCS:.c=.o)

FWORK	=	-lpthread -F ./frameworks/ -framework SDL2 -framework SDL2_image -framework SDL2_ttf \
			-framework SDL2_mixer -rpath ./frameworks/

LIB		=	libraries/libft/libft.a

RM		=	rm -rf

.SILENT	:

.PHONY	: 	all clean fclean re

#Colors
_BLACK=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libraries/libft/
			echo "$(_RED)Compiling libft... $(_GREEN)Done$(_END)"
			$(CC) -o $(NAME) $(OBJS) $(LIB) $(FWORK)

			echo "$(_RED) _       __      ___________ ____     _                             __         __"
			echo "$(_RED)| |     / /___  / / __/__  // __ \   (_)____   _________  ____ ____/ /_  __   / /"
			echo "$(_BLUE)| | /| / / __ \/ / /_  /_ </ / / /  / / ___/  / ___/ _  \/ __ / __  / / / /  / /"
			echo "$(_PURPLE)| |/ |/ / /_/ / / __/___/ / /_/ /  / (__  )  / /  /  __/ /_/ / /_/ / /_/ /  /_/"
			echo "$(_CYAN)|__/|__/\____/_/_/  /____/_____/  /_/____/  /_/   \___/\__,_/\__,_/\__, /  (_)"
			echo "$(_YELLOW)                                                                  /____/"
			echo "$(_WHITE)By $(_RED)nvienot and abechet $(_GREEN)2019 $(_YELLOW)!$(_WHITE)!$(_END)\n"

$(OBJS)	: 	%.o: %.c  Makefile includes/wolf3d.h includes/w3d_structs.h includes/w3d_defines.h
			$(CC) $(FLAGS) $(INCL) -c $< -o $@

clean	:
			make clean -C libraries/libft/
			$(RM) $(OBJS)
			echo "$(_RED)Cleaning obj... $(_GREEN)Done$(_END)"

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C libraries/libft/
			echo "$(_RED)Cleaning all... $(_GREEN)Done$(_END)"

re		:	fclean all

recl	:	re
			make clean

norm	:	fclean
			echo "$(_RED)Starting norminette...$(_END)"
			norminette $(SRCS) $(INCL_NORM) | grep -B 1 '^Error' 2> /dev/null && echo "$(_RED)Norm KO :(" || echo "$(_GREEN)Norm OK ! :)$(_END)";
