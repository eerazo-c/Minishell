//header
#include "../include/minishell.h"

int	count_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

char	**cpy_env(char **env)
{
	char	**cpy;
	int		i;
	int		size;

	i = 0;
	size = count_env(env);
	cpy = malloc(sizeof(char *) * (size + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cpy[i] = ft_strdup(env[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(env[i]) + ft_strlen(env[j]);
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strncmp(env[i], env[j], len) > 0)
			{
				tmp = env[i];
				env[i] = env[j];
				env[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	print_exported_vars(char **env_copy)
{
	int		i;
	char	*equal;

	i = 0;
	while (env_copy[i])
	{
		write(1, "declare -x", 11);
		equal = ft_strchr(env_copy[i], '=');
		if (equal)
		{
			write(1, env_copy[i], equal - env_copy[i]);
			write(1, "=\"", 2);
			write(1, equal + 1, ft_strlen(equal + 1));
			write(1, "\"\n", 2);
		}
		else
		{
			write(1, env_copy[i], ft_strlen(env_copy[i]));
			write(1, "\n", 1);
		}
		free(env_copy[i]);
		i++;
	}
	free(env_copy);
}

int	builtin_export(t_shell *shell, char **argv)
{
	char	**cpy;

	(void)argv;
	if (!shell || !shell->env)
		return (1);
	cpy = cpy_env(shell->env);
	if (!cpy)
		return (1);
	sort_env(cpy);
	print_exported_vars(cpy);
	return (0);
}

/*
static void	print_exported_vars(char **env_copy)
{
	int		i;
	char	*equal;

	i = 0;
	while (env_copy[i])
	{
		write(1, "declare -x", 11);
		equal = ft_strchr(env_copy[i], '=');
		if (equal)
		{
			write(1, env_copy[i], equal - env_copy[i]);
			write(1, "=\"", 2);
			write(1, equal + 1, ft_strlen(equal + 1));
			write(1, "\"\n", 2);
		}
		else
		{
			write(1, env_copy[i], ft_strlen(env_copy[i]));
			write(1, "\n", 1);
		}
		free(env_copy[i]);
		i++;
	}
	free(env_copy);
}

int	builtin_export(t_shell *shell, char **argv)
{
	char	**cpy;

	(void)argv;
	if (!shell || !shell->env)
		return (1);
	cpy = cpy_env(shell->env);
	if (!cpy)
		return (1);
	sort_env(cpy);
	print_exported_vars(cpy);
	return (0);
}
*/
