# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 15:21:19 by pallspic          #+#    #+#              #
#    Updated: 2019/07/24 17:11:46 by pallspic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#defending pseudo-rules from unexpected similiar-name files if directory
#
#Защита псевдоправил от случайного поведения, когда файлы с такими именами уже
#существуют в директории

.PHONY: all re clean fclean libft

CFLAGS = -Wall -Werror -Wextra -Iincludes

LIB_MAKE = make -C $(LIB_DIR)

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

NAME = libftprintf.a

SRC = 	utilities.c \
		put_number.c \
		put_double.c \
		ft_printf.c


OBJ = $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(LIB) $(OBJ)
	cp libft/libft.a .
	mv libft.a libftprintf.a
	ar rc libftprintf.a $(OBJ)

libft:
	$(LIB_MAKE)

%.a:
	$(LIB_MAKE)

%.o: %.c
	gcc -c $(CFLAGS) $<

fclean: clean
	rm -rf $(NAME)
	$(LIB_MAKE) fclean

clean:
	rm -rf $(OBJ)
	$(LIB_MAKE) clean

re: fclean all
