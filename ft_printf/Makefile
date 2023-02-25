# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 21:59:38 by mlagrini          #+#    #+#              #
#    Updated: 2022/10/24 19:51:41 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
		  ft_putchar.c \
		  ft_puthex.c \
		  ft_putstr.c \
		  ft_putuphex.c \
		  ft_strlen.c \
		  ft_putunsigned.c \
		  ft_putnbr.c \
		  ft_putadrs.c
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
NAME	= libftprintf.a

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

$(NAME): ${OBJS}
		ar rc ${NAME} $^

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
