# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 15:11:35 by pedrohe3          #+#    #+#              #
#    Updated: 2025/11/10 21:32:04 by pedrohe3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L libft -lft

NAME = libprintf.a

CFILES = ft_printf.c

OBJECTS = $(CFILES:.c=.o)

### Standard rules ###
all: $(libft) $(NAME)

$(libft):
	make -s bonus -C libft

$(NAME): $(OBJECTS)
	ar -crs $@ $^

%.o : %.c
	cc $(CFLAGS) -c -o $@ $^ -I libft

### Control rules ###
clean: $(OBJECTS)
	rm -rf $^
	make -s clean -C libft

fclean: clean
	rm -rf $(NAME)
	make -s fclean -C libft

re: fclean all

.PHONY: clean fclean re all
