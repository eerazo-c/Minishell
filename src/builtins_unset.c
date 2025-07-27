/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:07:07 by elerazo-          #+#    #+#             */
/*   Updated: 2025/07/27 15:56:53 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

//funciones que modifican el entorno
//estas funciones agregan, quitan o validan variables de entorno.

static int	ft_error(void)
{
	write (1, "\e[0;31mError\e[0m\n", 17);
	exit(1);
	return (-1);
}

int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (!((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] == '_')))
		return (ft_error());
	i++;
	while (str[i])
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9')
				|| (str[i] == '_')))
			return (ft_error());
		i++;
	}
	return (1);
}

static void	remove_unset_var(char **env, char *var)
{
	int	j;
	int	k;

	j = 0;
	while (env[j])
	{
		if (ft_strncmp(env[j], var, ft_strlen(var)) == 0
			&& env[j][ft_strlen(var)] == '=')
		{
			k = j;
			while (env[k])
			{
				env[k] = env[k + 1];
				k++;
			}
			break ;
		}
		j++;
	}
}

int	builtin_unset(t_shell *shell, char **argv)
{
	int	i;

	if (!shell || !shell->env)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (!is_valid_identifier(argv[i]))
		{
			write(2, "unset: not a valid identifier\n", 29);
			i++;
			continue ;
		}
		remove_unset_var(shell->env, argv[i]);
		i++;
	}
	return (0);
}
