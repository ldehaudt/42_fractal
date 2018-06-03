# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 22:58:27 by ldehaudt          #+#    #+#              #
#    Updated: 2018/05/01 22:04:25 by ldehaudt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = *.c

OFILES = *.o

all: $(NAME)
	
$(NAME)	:
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OFILES)

clean:
	rm -f *.o

fclean: clean
	rm -f  $(NAME)

re: fclean all clean
