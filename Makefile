# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 13:23:18 by csouza-f          #+#    #+#              #
#    Updated: 2020/10/17 14:43:51 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

all: $(NAME)

SRCS = main.c ft_putstr.c

OBJS = $(patsubst %.c, build/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	clang $^ $(LIBRARY) -o $@

$(NAME): $(OBJS)
	clang $^ -o $@

build/%.o: %.c
	clang -Wall -Wextra -Werror -c -o $@ $< -I includes/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
