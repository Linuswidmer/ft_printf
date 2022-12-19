# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 09:51:03 by lwidmer           #+#    #+#              #
#    Updated: 2022/12/16 10:44:22 by lwidmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile to compile the ft_printf project 

NAME = ft_printf
LIBRARY = libft

FILENAMES = main ft_printf ft_intlen ft_putnbr_base ft_hexlen ft_print_address_hex

SRCS_DIR = ./sources_ft_printf/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILENAMES)))

OBJS_DIR = ./sources_ft_printf/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILENAMES)))
CFLAGS = -Werror -Wall -Wextra

INCLUDES_DIR = -I./includes_ft_printf/ -I./libft/includes/

LIB_DIR = ./libft/
LIB_INCLUDE = $(addprefix $(LIB_DIR), $(addsuffix .a, $(LIBRARY)))

ft_printf: ${OBJS}
	cc ${CFLAGS} ${OBJS} -L. ./libft/libft.a
	./a.out

.c.o: ${SRCS}
	cc ${CFLAGS} -c -o $@ $< ${INCLUDES_DIR}

all: ${NAME} clean

test: ${OBJS}
	for number in 0 1 2 3 4 5 6 7; do \
			./a.out $$number ; \
		done
#	cc ${CFLAGS} ${OBJS} -L. ./libft/libft.a


clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

git:
	git add .
	git commit -m "$m"
	git push origin main

${LIBRARY}: 
	cd ${LIBRARY} && \
	make re

.PHONY: all clean fclean re
