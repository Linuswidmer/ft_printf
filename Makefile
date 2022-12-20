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

NAME = libftprintf.a

FILENAMES_FT_PRINTF = ft_printf \
											ft_intlen \
											ft_putnbr_base \
											ft_hexlen \
											ft_print_address_hex

FILENAMES_LIBFT = ft_isalpha \
			ft_isdigit \
			ft_isprint \
			ft_isascii \
			ft_isalnum \
			ft_strlen \
			ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_itoa \
			ft_strdup \
			ft_strmapi \
			ft_striteri \
			ft_strlcpy \
			ft_strlcat \
			ft_toupper \
			ft_tolower \
			ft_strchr \
			ft_strrchr \
			ft_strncmp \
			ft_strnstr \
			ft_atoi \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_calloc \
			ft_lstnew_bonus \
			ft_lstadd_front_bonus \
			ft_lstsize_bonus \
			ft_lstlast_bonus \
			ft_lstadd_back_bonus \
			ft_lstdelone_bonus \
			ft_lstclear_bonus \
			ft_lstiter_bonus \
			ft_lstmap_bonus

SRCS_FT_PRINTF_DIR = ./sources_ft_printf/
SRCS_FT_PRINTF = $(addprefix $(SRCS_FT_PRINTF_DIR), $(addsuffix .c, $(FILENAMES_FT_PRINTF)))
SRCS_LIBFT_DIR = ./libft/sources_libft/
SRCS_LIBFT = $(addprefix $(SRCS_LIBFT_DIR), $(addsuffix .c, $(FILENAMES_LIBFT)))

OBJS_FT_PRINTF_DIR = ./sources_ft_printf/
OBJS_FT_PRINTF = $(addprefix $(OBJS_FT_PRINTF_DIR), $(addsuffix .o, $(FILENAMES_FT_PRINTF)))
OBJS_LIBFT_DIR = ./libft/sources_libft/
OBJS_LIBFT = $(addprefix $(SRCS_LIBFT_DIR), $(addsuffix .o, $(FILENAMES_LIBFT)))

SRCS = $(SRCS_LIBFT) $(SRCS_FT_PRINTF)
OBJS = $(OBJS_LIBFT) $(OBJS_FT_PRINTF)

CFLAGS = -Werror -Wall -Wextra

INCLUDES_DIR = -I./includes_ft_printf/ -I./libft/includes/

#LIB_DIR = ./libft/
LIB_INCLUDE = $(addprefix $(LIB_DIR), $(addsuffix .a, $(LIBRARY)))

${NAME}: ${OBJS}
	ar rc $@ $^
	ranlib ${NAME}

# $(NAME): ${OBJS}
# 	cc ${CFLAGS} ${OBJS} -L. ./libft/libft.a
# 	./a.out

.c.o: ${SRCS}
	cc ${CFLAGS} -c -o $@ $< ${INCLUDES_DIR}

all: ${NAME} clean

# test: ${OBJS}
# 	cc ${CFLAGS} ${OBJS} -L. ./libft/libft.a
# 	for arg in INT_TEST_ U_INT_TEST_ STR_TEST_; do \
# 		for number in 0 1 2 3 4 5 6 7 8; do \
# 			for fun in _FT _ORG; do \
# 				./a.out $$arg $$number $$fun > test_outputs/$$arg$$number$$fun.output; \
# 			done \
# 		done \
# 	done

# test for binary differences with "diff"

clean:
	rm -rf ${OBJS_FT_PRINTF} ${OBJS_LIBFT}

fclean: clean
	rm -rf ${NAME}

re: fclean all

git:
	git add .
	git commit -m "$m"
	git push origin main

# ${LIBRARY}: 
# 	cd ${LIBRARY} && \
# 	make re

.PHONY: all clean fclean re
