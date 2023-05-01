# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 11:44:46 by ahammad           #+#    #+#              #
#    Updated: 2023/05/01 20:00:08 by ahammad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.cpp PmergeMe.cpp
OBJS	=	$(SRCS:.cpp=.o)
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME	=	PmergeMe
CC		=	c++

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
all:	${NAME}
${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
clean:
			rm -f ${OBJS}
fclean:		clean
			rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re