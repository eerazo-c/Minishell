/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:17:35 by elerazo-          #+#    #+#             */
/*   Updated: 2025/08/12 13:17:39 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

// returns 1 for err cases, returns 0 either it has deleted a node or not
int	check_var_and_del(t_list **head, char *var)
{
	t_list	*node;

	if (*head == NULL || NULL == var)
		return (ft_putstr_fd("minishell: unset: missing argument\n", 2), 1);
	node = locate_env_var(*head, var);
	if (NULL != node)
		ft_lstremove_and_link(head, node);
	return (0);
}

// Function will iter over args and delete every env var that matches its name
int	builtin_unset(t_shell *shell, char **argv)
{
	char	**new_env;
	size_t	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (check_var_and_del(&shell->raw_env, argv[i]) == 1)
			break ;
		i++;
	}
	new_env = env_compiler(shell->raw_env);
	if (new_env != NULL)
	{
		free_array(shell->env);
		shell->env = new_env;
		return (0);
	}
	return (1);
}
