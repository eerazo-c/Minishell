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
			if (ft_strncmp(env[i], env[j], len) > 0) //here funtion
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

int	builtin_export(t_shell *shell, char **argv)
{
	char	**cpy;
	int		i;
	char	*equal;

	(void)argv;
	if (!shell || !shell->env) //revision si hay entorno
		return (1);
	cpy = cpy_env(shell->env);
	if (!cpy)
		return (1);
	sort_env(cpy); //copia y ordena la variable
	i = 0;
	while (cpy[i])
	{
		write(1, "declare -x", 11);
		equal = ft_strchr(cpy[i], '=');
		if (equal)
		{
			write(1, cpy[i], equal - cpy[i]);
			write(1, "=\"", 2);
			write(1, equal + 1, ft_strlen(equal + 1));
			write(1, "\"\n", 2);
		}
		else
		{
			write(1, cpy[i], ft_strlen(cpy[i]));
			write(1, "\n", 1);
		}
		free(cpy[i++]);
	}
	free(cpy);
	return (0);
}
