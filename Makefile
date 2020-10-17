# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 13:23:18 by csouza-f          #+#    #+#              #
#    Updated: 2020/10/17 15:38:56 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c ft_putstr.c

OBJS = $(patsubst %.c, build/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	clang $^ -o $@

build/%.o: %.c
	clang -Wall -Wextra -Werror -c -o $@ $< -I includes/

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C get_next_line

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C get_next_line

re: fclean all
