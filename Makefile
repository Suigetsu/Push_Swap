# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 20:29:42 by mlagrini          #+#    #+#              #
#    Updated: 2023/04/01 10:10:19 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ps_checkargs.c ps_utils.c ps_utils2.c ps_push_instructions.c \
				ps_rev_rotate_instructions.c ps_sort3to5.c ps_sortbig.c \
				ps_rotate_instructions.c ps_swap_instructions.c ps_tointeger.c \
				push_swap.c
SRC_BNS		=	ps_checkargs.c ps_tointeger.c ps_utils.c ps_utils2.c ps_checker_utils.c \
				ps_checker_instruc.c ps_checker_instruc2.c ps_checker_instruc3.c \
				ps_checker_instruc4.c ps_checker.c
GNL			=	gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS		=	${SRC:.c=.o}
BNS_OBJS	=	${SRC_BNS:.c=.o} ${GNL:.c=.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
LIBFT		=	libft/libft.a ft_printf/libftprintf.a
INCLUDES	=	-I push_swap.h
NAME		=	push_swap
BNS			=	checker

all:	${NAME}

bonus:	${BNS}

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
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

.PHONY: all clean fclean
