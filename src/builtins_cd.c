/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:16:11 by elerazo-          #+#    #+#             */
/*   Updated: 2025/08/12 13:16:17 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

static int	aux_chdir(char **path, char **oldpwd)
{
	if (chdir(*path) != 0)
	{
		perror("minishell: cd");
		free(*oldpwd);
		return (FALSE);
	}
	return (TRUE);
}

static int	aux_nullpath(char **path, char **oldpwd)
{
	if (NULL == *path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
		free(*oldpwd);
		*oldpwd = NULL;
		return (FALSE);
	}
	return (TRUE);
}

static int	aux_guard(char **argv)
{
	if (argv[1] && argv[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return (FALSE);
	}
	return (TRUE);
}

static int	aux_path(char **path, char **argv, t_shell *shell)
{
	*path = argv[1];
	if (NULL == *path || ((*path)[0] == '~' && (*path)[1] == '\0'))
		*path = get_env_value(shell, "HOME");
	else if ((*path)[0] == '-' && (*path)[1] == '\0')
		*path = get_env_value(shell, "OLDPWD");
	if (*path == NULL)
		return (FALSE);
	return (TRUE);
}

int	builtin_cd(t_shell *shell, char **argv)
{
	char	*path;
	char	cwd[PATH_MAX];
	char	*oldpwd;

	if (aux_guard(argv) == FALSE)
		return (1);
	oldpwd = getcwd(NULL, 0);
	if (FALSE == aux_path(&path, argv, shell))
		if (FALSE == aux_nullpath(&path, &oldpwd))
			return (1);
	if (FALSE == aux_chdir(&path, &oldpwd))
		return (1);
	set_env_var(shell, "OLDPWD", oldpwd);
	getcwd(cwd, sizeof(cwd));
	set_env_var(shell, "PWD", cwd);
	free(oldpwd);
	return (0);
}
