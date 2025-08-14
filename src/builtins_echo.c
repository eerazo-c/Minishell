/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:16:47 by elerazo-          #+#    #+#             */
/*   Updated: 2025/08/12 13:16:54 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

int	builtin_echo(t_shell *shell, char **argv)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	(void)shell;
	if (argv[1] && ft_strcmp(argv[1], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1] != NULL && argv[i][0] != '\0')
			if (argv[i + 1] != NULL && argv[i + 1][0] != '\0')
				ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (newline == 1)
		ft_putchar_fd('\n', STDOUT_FILENO);
	shell->last_status = 0;
	return (shell->last_status);
}
