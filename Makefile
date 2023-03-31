# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 20:29:42 by mlagrini          #+#    #+#              #
#    Updated: 2023/03/31 08:15:28 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ps_checkargs.c ps_utils.c ps_utils2.c ps_push_instructions.c \
				ps_rev_rotate_instructions.c ps_sort3to5.c ps_sortbig.c \
				ps_rotate_instructions.c ps_swap_instructions.c ps_tointeger.c \
				push_swap.c
OBJS		=	${SRC:.c=.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
LIBFT		=	libft/libft.a ft_printf/libftprintf.a
INCLUDES	=	-I push_swap.h
NAME		=	push_swap


all:	${NAME}

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
		make -C libft
		make -C ft_printf

${NAME}: ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIBFT} -o $@
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
