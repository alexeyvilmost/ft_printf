# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pallspic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 20:50:17 by pallspic          #+#    #+#              #
#    Updated: 2019/08/26 02:25:12 by pallspic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean del check

.SECONDARY: $(OBJ)

override ARFLAGS = rc

override CFLAGS = -Wall -Werror -Wextra -I.

override CC = gcc

NAME = libft.a

SRC = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_isspace.c ft_itoa.c ft_bzero.c ft_memalloc.c ft_lstiter.c \
	  ft_memcpy.c ft_memcmp.c ft_memset.c ft_memchr.c ft_memmove.c ft_memdel.c \
	  ft_memccpy.c ft_putnbr.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_lstmap.c \
	  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	  ft_strclr.c ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strsplit.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_strnequ.c ft_striter.c \
	  ft_striteri.c ft_strjoin.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strnew.c ft_strstr.c ft_strnstr.c ft_strsub.c ft_strtrim.c \
	  ft_toupper.c ft_tolower.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_extra_funcs/ft_strrev.c \
	  ft_extra_funcs/ft_strfchr.c \
	  ft_extra_funcs/ft_strerase.c \
	  ft_extra_funcs/ft_abs.c \
	  ft_extra_funcs/ft_itoa_base.c \
	  ft_extra_funcs/ft_pow.c \
	  ft_extra_funcs/ft_nmult.c \
	  ft_extra_funcs/ft_nsize.c \
	  ft_extra_funcs/ft_strjoinfree.c \
	  ft_extra_funcs/ft_isupper.c \
	  ft_extra_funcs/ft_islower.c \
	  ft_extra_funcs/ft_get.c \
	  ft_extra_funcs/ft_max.c \
	  ft_extra_funcs/ft_memsetloc.c \
	  ft_long_math/ft_long.c \
	  ft_long_math/ft_long_div.c \
	  ft_long_math/ft_long_diff.c \
	  ft_long_math/ft_long_sum.c \
	  ft_long_math/ft_long_utils.c \
	  ft_long_math/ft_make_nline.c \
	  ft_long_math/ft_long_mult.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -o $@

all: $(NAME)

$(NAME): $(NAME)($(OBJ))
	ranlib $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean del

del:
	/bin/rm -f $(NAME)

re: fclean all

check: del all clean