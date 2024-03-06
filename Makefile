# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 19:13:24 by kmoshker          #+#    #+#              #
#    Updated: 2024/03/06 22:22:15 by kmoshker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS = error.c \
		fdf.c \
		main.c \
		read_file.c \
 
OBJS = ${SRCS:.c=.o}
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
# -fsanitize=address
AR = ar rs
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): $(LIBFT) ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

$(LIBFT): 
	make -C ./libft
clean:
	make clean -C ./libft
	${RM} ${OBJS}

fclean:	clean
	make clean -C ./libft
	${RM} $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft