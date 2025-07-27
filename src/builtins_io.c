/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:03:07 by elerazo-          #+#    #+#             */
/*   Updated: 2025/07/27 16:09:56 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

/*funciones que imprimen o trabajan con I/O
funciones imprimen cosas al usuario, sin modificar el entorno.*/

static	int	is_dash_n(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(t_shell *shell, char **argv)
{
	int	i;
	int	flag_n;

	i = 1;
	flag_n = 0;
	(void)shell;
	while (argv[i] && is_dash_n(argv[i]))
	{
		flag_n = 1;
		i++;
	}
	while (argv[i])
	{
		write (1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write (1, " ", 1);
		i++;
	}
	if (!flag_n)
		write (1, "\n", 1);
	return (0);
}

int	builtin_pwd(t_shell *shell, char **argv)
{
	int		i;
	char	buffer[1024];

	(void)shell;
	i = 0;
	while (argv[i])
		i++;
	if (getcwd(buffer, sizeof(buffer)) != NULL)
	{
		write (1, buffer, ft_strlen(buffer));
		write (1, "\n", 1);
	}
	else
		write (1, "\e[0;31mError\e[0m\n", 17);
	return (0);
}

int	builtin_env(t_shell *shell, char **argv)
{
	int	i;
	int	j;

	(void)argv;
	if (!shell || !shell->env)
		return (1);
	i = 0;
	while (shell->env[i])
	{
		j = 0;
		while (shell->env[i][j] && shell->env[i][j] != '=')
			j++;
		if (shell->env[i][j] == '=')
		{
			write (1, shell->env[i], ft_strlen(shell->env[i]));
			write (1, "\n", 1);
		}
		i++;
	}
	return (0);
}
