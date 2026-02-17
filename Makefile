# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 15:11:35 by pedrohe3          #+#    #+#              #
#    Updated: 2026/02/17 17:02:10 by pedrohe3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L libft -lft

NAME = libftprintf.a

CFILES = ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putptr_pf.c \
	 ft_putnbr_base_pf.c ft_putnbr_pf.c ft_puthex_pf.c ft_putuint_pf.c

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(libft) $(OBJECTS)
	cp $(libft) $(NAME)
	ar -crs $@ $^

$(libft):
	make -s bonus -C libft

%.o : %.c
	cc $(CFLAGS) -c -o $@ $^ -I libft

### Control rules ###
clean: 
	rm -rf $(OBJECTS)
	make -s clean -C libft

fclean: clean
	rm -rf $(NAME)
	make -s fclean -C libft

re: fclean all

.PHONY: clean fclean re all
