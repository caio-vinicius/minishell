# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 13:23:18 by csouza-f          #+#    #+#              #
#    Updated: 2020/10/17 13:23:20 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

all: $(NAME)

SRCS = main.c

OBJS = $(patsubst %.c, build/%.o, $(SRCS))

$(info $(OBJS))

$(NAME): $(OBJS)
	clang $^ -o $@

build/%.o: %.c
	clang -Wall -Wextra -Werror -c -o $@ $< -I includes/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
