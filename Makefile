#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 15:15:55 by tmaslyan          #+#    #+#              #
#    Updated: 2018/04/16 15:15:56 by tmaslyan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

HEAD = ft_printf.h
SOURCES = ft_printf.c

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OPTION = -c -I $(HEAD)
OBJ = ft_printf.o

all: $(NAME)
$(NAME):
	gcc $(FLAGS) $(OPTION) $(SOURCES)
	ar rc $(NAME) $(OBJ)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all