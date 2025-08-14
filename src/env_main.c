/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	gtfo_env_crash(t_shell *shell)
{
	shell->last_status = 2;
	exit(shell->last_status);
}

int	generate_and_fill_arr(char ***arr, int i, t_list *lst)
{
	t_list	*node;

	node = lst;
	*arr = malloc(sizeof(char *) * (i + 1));
	if (NULL == *arr)
		return (1);
	(*arr)[i] = NULL;
	i = 0;
	while (NULL != node)
	{
		(*arr)[i] = ft_strdup((char *)node->content);
		if ((*arr)[i] == NULL)
			return (free_array(*arr), 1);
		node = node->next;
		i++;
	}
	return (0);
}

char	**env_compiler(t_list *head)
{
	char	**arr;
	t_list	*iter;
	int		i;

	iter = head;
	i = 0;
	while (iter != NULL)
	{
		iter = iter->next;
		i++;
	}
	arr = NULL;
	if (1 == generate_and_fill_arr(&arr, i, head))
		return (wrapper_free_lst(head), NULL);
	return (arr);
}

// Retrieves the value of an env var if the name matches a env key
char	*get_env_value(t_shell *shell, const char *name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], name, len) == 0
			&& shell->env[i][len] == '=')
			return (shell->env[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	set_env_var(t_shell *shell, const char *name, const char *value)
{
	char	*var;

	var = NULL;
	if (check_var_and_del(&shell->raw_env, (char *)name) == 1)
		gtfo_env_crash(shell);
	if (wrapper_strjoin(&var, (char *)name) == FALSE)
		gtfo_env_crash(shell);
	if (wrapper_strjoin(&var, "=") == FALSE)
		gtfo_env_crash(shell);
	if (wrapper_strjoin(&var, (char *)value) == FALSE)
		gtfo_env_crash(shell);
	shell->last_status = update_env(shell, var);
	free(var);
}
