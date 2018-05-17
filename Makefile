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
SOURCES =	ft_printf.c	\
			print_d.c	\
			start_x_o_u.c	\
			print_smth.c	\
			pass_spaces.c	\
			parse_flags.c		\
			print_o.c	\
			print_u.c	\
			print_x.c	\
			print_percent.c	\
			print_c.c 	\
			print_s.c	\
			print_p.c	\
			get_dnbr.c	\

NAME = libftprintf.a
SRCS  = $(addprefix src/, $(SOURCES))
OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
HDIR = include

all:$(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I $(HDIR)

gcc: all
	gcc $(FLAGS) main.c $(NAME)
	./a.out
clean :
	rm -f $(OBJ)
	make clean -C libft
	rm -f a.out
fclean : clean
	rm -f $(NAME)
	make fclean -C libft
re : fclean all
