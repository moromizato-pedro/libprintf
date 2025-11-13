# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 15:11:35 by pedrohe3          #+#    #+#              #
#    Updated: 2025/11/12 23:00:17 by pedrohe3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L libft -lft

NAME = libftprintf.a

CFILES = ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putptr_pf.c \
	 ft_putnbr_base_pf.c ft_putnbr_pf.c ft_puthex_pf.c ft_putuint_pf.c

OBJECTS = $(CFILES:.c=.o)

### Standard rules ###
all: $(libft) $(NAME)

$(libft):
	make -s bonus -C libft

$(NAME): $(OBJECTS)
	cp $(libft) $(NAME)
	ar -crs $@ $^

%.o : %.c
	cc $(CFLAGS) -c -o $@ $^ -I libft

test: ft_printf.c ft_printf.o
	cc $(CFLAGS) -c ft_printf.c -I libft -g
	cc ft_printf.o -o test -L. -L libft -lftprintf -lft

### Control rules ###
clean: 
	rm -rf $(OBJECTS)
	make -s clean -C libft

fclean: clean
	rm -rf $(NAME)
	make -s fclean -C libft

re: fclean all

.PHONY: clean fclean re all
