# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 14:10:45 by nvienot           #+#    #+#              #
#    Updated: 2019/05/21 15:20:14 by nvienot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcat.c ft_strchr.c \
ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strstr.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c ft_strrchr.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strnstr.c \
ft_putendl.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strclr.c ft_strdel.c ft_strnew.c ft_memalloc.c ft_memdel.c ft_memccpy.c \
ft_strequ.c ft_strnequ.c ft_itoa.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_strjoin.c ft_strsub.c ft_strtrim.c ft_strsplit.c ft_lstadd.c \
ft_isnumber.c ft_lstiter.c ft_lstdel.c ft_lstdelone.c ft_lstmap.c ft_swap.c \
ft_lstnew.c ft_iswhitespace.c ft_strlcpy.c ft_sortinttab.c ft_strndup.c \
ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c ft_ishexa.c \
ft_str_is_printable.c ft_str_is_uppercase.c ft_strcapitalize.c \
ft_strupcase.c ft_strlowcase.c ft_isupper.c ft_islower.c ft_data_in_tab.c \
ft_strsplit_at_first_c.c get_next_line.c ft_atoi_base.c ft_is_present.c \
ft_getfirstdecimal.c ft_strjoinnfree.c get_next_line_max.c

OBJS = $(SRCS:.c=.o)

.SILENT	:

all: $(NAME)

$(NAME): $(OBJS) libft.h
	$(CC) $(FLAGS) -c $(SRCS) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

recl: all clean