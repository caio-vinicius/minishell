/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:58:22 by csouza-f          #+#    #+#             */
/*   Updated: 2020/10/17 15:31:30 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *get_line(void)
{
	char *buffer;
	char c;
	int i;
	
	//free after	
	buffer = malloc(sizeof(char) * 1024);
	i = 0;
	while (1)
	{
		read(0, &c, 1);
		if (c == '\0' || c == '\n')
		{
			buffer[i] = '\0';
			return (buffer);
		}
		else
			buffer[i] = c;
		i++;
	}
}

void prompt(void)
{
	char *line;
	
	while (1)
	{
		ft_putstr("minishell> ");
		line = get_line();
		//ft_putstr(line);
	}
}

int main(void)
{
	prompt();
	return (0);
}
