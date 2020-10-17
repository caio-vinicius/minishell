/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:39:10 by csouza-f          #+#    #+#             */
/*   Updated: 2020/10/17 14:28:55 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}
