/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:08:53 by elerazo-          #+#    #+#             */
/*   Updated: 2025/07/27 16:37:01 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

//funciones varias / control de shell
//cd y exit no imprimen cosas ni modifican el entorno
//de forma directa, sino que afectan el estado del shell o el proceso.

char	**append_env(char **env, char *new_var)
{
	int		len;
	char	**new_env;
	int		i;

	len = 0;
	while (env && env[len])
		len++;
	new_env = malloc(sizeof(char *) * (len + 2));
	if (!new_env)
		return (env);
	i = 0;
	while (i < len)
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[i++] = strdup(new_var);
	new_env[i] = NULL;
	free(env);
	return (new_env);
}

char	*get_ev_value(char **env, char *key)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(key);
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, len) && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	update_env(t_shell *shell, char *key, char *value)
{
	int		i;
	char	*new_var;
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return ;
	new_var = ft_strjoin(tmp, value);
	free(tmp);
	if (!new_var)
		return ;
	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], key, ft_strlen(key)) == 0
			&& shell->env[i][ft_strlen(key)] == '=')
		{
			free(shell->env[i]);
			shell->env[i] = new_var;
			return ;
		}
		i++;
	}
	shell->env = append_env(shell->env, new_var);
	free(new_var);
}

void	update_pwd(t_shell *shell)
{
	char	buffer[1024];

	if (getcwd(buffer, sizeof(buffer)) != NULL)
		update_env(shell, "PWD", buffer);
}

int	builtin_cd(t_shell *shell, char **argv)
{
	char	*path;
	char	oldpwd[1024];

	if (!shell || !shell->env)
		return (1);
	getcwd(oldpwd, sizeof(oldpwd));
	if (!argv[1])
	{
		path = get_env_value(shell, "HOME");
		if (!path)
		{
			write(2, "cd: HOME not set\n", 18);
			return (1);
		}
	}
	else
		path = argv[1];
	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	update_env(shell, "OLDPWD", oldpwd);
	update_pwd(shell);
	return (0);
}
