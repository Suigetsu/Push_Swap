# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 20:29:42 by mlagrini          #+#    #+#              #
#    Updated: 2023/03/31 16:20:46 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ps_checkargs.c ps_utils.c ps_utils2.c ps_push_instructions.c \
				ps_rev_rotate_instructions.c ps_sort3to5.c ps_sortbig.c \
				ps_rotate_instructions.c ps_swap_instructions.c ps_tointeger.c
SRC_MAIN	=	push_swap.c
SRC_BNS		=	ps_checker_utils.c ps_checker.c
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

all:	${NAME} ${BNS}

bonus:	${BNS}

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
		make -C libft
		make -C ft_printf
${SRC_MAIN}:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT} ${SRC_MAIN}
		${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIBFT} ${SRC_MAIN} -o $@
		clear

${BNS}:	${BNS_OBJS} ${OBJS} ${LIBFT} ${NAME}
		${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${BNS_OBJS} ${LIBFT} -o $@
		clear

clean:
		cd libft && make clean
		cd ft_printf && make clean
		${RM} ${OBJS} ${BNS_OBJS} push_swap.o
		

fclean: clean
		${RM} ${NAME} ${BNS} 
		cd libft && make fclean
		cd ft_printf && make fclean
		clear

re: fclean all

.PHONY: all clean fclean
