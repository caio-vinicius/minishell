/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:58:22 by csouza-f          #+#    #+#             */
/*   Updated: 2020/10/18 12:00:42 by csouza-f         ###   ########.fr       */
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

int execute(char *argv[])
{
	pid_t pid;
	pid_t wpid;
	int status;
	
	status = 0;
	char *env[] = { NULL };
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			perror("minishell");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("minishell");
	else
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	return (1);
}



int ms_exit(char **args)
{
	UNUSED(args);
	return (0);
}

int ms_cd(char **args)
{
	if (args[1] == NULL)
		ft_putstr("minishell: expected argument to cd.\n");
	else
		if (chdir(args[1]) != 0)
			perror("minishell");
	return (1);
}

void ms_help(char **args)
{
	UNUSED(args);
	ft_putstr("help!");
}

int is_builtin(char **args)
{
	char *builtins[] = {"cd", "help", "exit"}; 
	int num_builtins;

	num_builtins = sizeof(builtins) / sizeof(char *);

	while (num_builtins)
	{
		num_builtins--;
		if (ft_strncmp(args[0], builtins[num_builtins], ft_strlen(builtins[num_builtins])) == 0)
			return (num_builtins);
	}
	return (-1);
}

void prompt(void)
{
	char s[100];
	char *line;
	char **args;
	//int status;
	int builtin;

	while (1)
	{
		//shell prompt
		ft_putstr("mini@shell:");
		ft_putstr(getcwd(s, 100));
		ft_putstr("$ ");
		line = get_line();
		args = ft_split(line, ' ');
		if ((builtin = is_builtin(args)) != -1)
		{
			ft_putstr("is built in!");
			if (builtin == 0)
				ms_cd(args);
			else if (builtin == 1)
				ms_help(args);
			else if (builtin == 2)
				ms_exit(args);
		}
		else
			ft_putstr("is not built in!");
		//execute(args);
	}
}

int main(void)
{
	prompt();
	return (0);
}
