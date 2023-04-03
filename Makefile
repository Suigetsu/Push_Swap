# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 20:29:42 by mlagrini          #+#    #+#              #
#    Updated: 2023/04/03 07:50:39 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ps_checkargs.c ps_utils.c ps_utils2.c ps_push_instructions.c \
				ps_rev_rotate_instructions.c ps_sort3to5.c ps_sortbig.c \
				ps_rotate_instructions.c ps_swap_instructions.c ps_tointeger.c \
				push_swap.c
SRC_BNS		=	ps_checkargs.c ps_tointeger.c ps_utils.c ps_utils2.c \
				ps_checker_utils.c ps_checker_instruc.c ps_checker_instruc2.c \
				ps_checker_instruc3.c ps_checker_instruc4.c ps_checker.c
GNL			=	gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS		=	${SRC:.c=.o}
BNS_OBJS	=	${SRC_BNS:.c=.o} ${GNL:.c=.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
LIBFT_SRC	=	libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
				libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
				libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c \
				libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
				libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
				libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c \
				libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
				libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
				libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
				libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c \
				libft/ft_toupper.c ft_printf/ft_printf.c \
				ft_printf/ft_putadrs.c ft_printf/ft_putchar.c \
				ft_printf/ft_puthex.c ft_printf/ft_putnbr.c \
				ft_printf/ft_putstr.c ft_printf/ft_putunsigned.c \
				ft_printf/ft_puthex.c
LIBFT		=	libft/libft.a ft_printf/libftprintf.a
INCLUDES	=	-I push_swap.h
NAME		=	push_swap
BNS			=	checker

all:	${NAME} ${LIBFT}

bonus:	${BNS}

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}: ${LIBFT_SRC}
		make -C libft
		make -C ft_printf

${NAME}: ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIBFT} -o $@
		clear

${BNS}:	${BNS_OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${INCLUDES} ${BNS_OBJS} ${LIBFT} -o $@
		clear

clean:
		cd libft && make clean
		cd ft_printf && make clean
		${RM} ${OBJS} ${BNS_OBJS}
		

fclean: clean
		${RM} ${NAME} ${BNS} 
		cd libft && make fclean
		cd ft_printf && make fclean
		clear

re: fclean all

.PHONY: all clean fclean bonus
