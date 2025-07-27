//header
#include "../include/minishell.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	clean_shell(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->env)
		free_matrix(shell->env);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit(t_shell *shell, char **argv)
{
	int	status;

	write(1, "exit\n", 5);
	if (!argv[1])
		exit(0);
	if (!is_numeric(argv[1]))
	{
		write(2, "exit: numeric argument required\n", 32);
		clean_shell(shell);
		exit(255);
	}
	if (argv[2])
	{
		write(2, "exit: too many arguments\n", 26);
		return (1);
	}
	status = ft_atoi(argv[1]);
	clean_shell(shell);
	exit(status % 256);
	return (0);
}
