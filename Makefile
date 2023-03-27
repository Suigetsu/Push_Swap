# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 20:29:42 by mlagrini          #+#    #+#              #
#    Updated: 2023/03/27 13:42:59 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ps_checkargs.c ps_tointeger.c ps_push_instructions.c \
				ps_rev_rotate_instructions.c ps_rotate_instructions.c \
				ps_sort3.c ps_swap_instructions.c ps_free_nodes.c \
				ps_sort100.c ps_draft.c main.c
OBJS		=	${SRC:.c=.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf
LIBFT		=	libft/libft.a ft_printf/libftprintf.a
# INCLUDES	=	-I push_swap.h
NAME		=	push_swap


all:	${NAME}

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
		make -C libft
		make -C ft_printf

${NAME}: ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o $@
		clear

clean:
		cd libft && make clean
		cd ft_printf && make clean
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
		cd libft && make fclean
		cd ft_printf && make fclean
		clear

re: fclean all

.PHONY: all clean fclean
