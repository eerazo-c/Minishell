/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*assemble_expansion(char *token_value, t_expand *dt)
{
	char	*new;
	char	*tmp;
	size_t	i;
	size_t	len;

	i = dt->to_expand - token_value;
	new = ft_substr(token_value, 0, i);
	if (new == NULL)
		return (NULL);
	tmp = dt->matching_env;
	dt->matching_env = ft_strchr(dt->matching_env, '=');
	if (dt->matching_env != NULL)
		dt->matching_env++;
	if (wrapper_strjoin(&new, dt->matching_env) == FALSE)
		perror("cant assamble expansion 2");
	len = ft_strlen(dt->var_name) + 1;
	dt->to_expand += len;
	if (wrapper_strjoin(&new, dt->to_expand) == FALSE)
		perror("cant assamble expansion 3");
	if (dt->false_env == 1)
	{
		free_wrapper((void **)&tmp);
		dt->false_env = 0;
	}
	return (new);
}

static int	aux_guard_interr(t_expand *dt, t_shell *sh)
{
	int		check;
	char	*tmp;
	char	*err_str;

	err_str = NULL;
	check = ft_strncmp(dt->var_name, "?", ft_strlen(dt->var_name));
	if (check == 0)
	{
		tmp = ft_itoa(sh->last_status);
		if (tmp)
			err_str = ft_strjoin("=", tmp);
		free_wrapper((void **)&tmp);
		dt->false_env = aux_upd_data(dt, dt->to_expand, dt->var_name, err_str);
		return (1);
	}
	return (0);
}

static int	aux_upd_node(t_expand *dt, t_list **node, t_shell *shell)
{
	if (aux_guard_interr(dt, shell) == 1)
		return (1);
	*node = locate_env_var(shell->raw_env, dt->var_name);
	if (*node == NULL && ft_strcmp(dt->var_name, "=") == 0)
		dt->false_env = aux_upd_data(dt, dt->to_expand, dt->var_name, \
								ft_strdup("="));
	else if (*node == NULL)
		dt->false_env = aux_upd_data(dt, dt->to_expand, dt->var_name, \
								ft_strdup("="));
	else
		aux_upd_data(dt, dt->to_expand, dt->var_name, (*node)->content);
	return (1);
}

// Retrieves the $str from the tkn.value, then iterates over env
// looking for a match. For no match, returns 1, else 0 there's match
static int	is_expandable(t_token tkn, t_expand *dt, t_shell *shl)
{
	t_list	*node;
	char	*var_name;
	char	*match;
	char	*iter;

	if (tkn.type != TOKEN_WORD_DQ && tkn.type != TOKEN_WORD)
		return (1);
	iter = tkn.value;
	match = NULL;
	while (match == NULL)
	{
		match = ft_strchr(iter, '$');
		if (match == NULL)
			return (1);
		var_name = get_var_name(match);
		aux_upd_data(dt, match, var_name, NULL);
		if (var_name != NULL && aux_upd_node(dt, &node, shl))
			break ;
		free_wrapper((void **)&var_name);
		iter = ++match;
		match = NULL;
	}
	return (0);
}

int	expand_variables(t_shell *shell, t_token *head)
{
	t_expand	dt;
	t_token		*tkn;
	t_token		*next;

	init_expand(&dt);
	next = head;
	while (NULL != next)
	{
		tkn = next;
		next = tkn->next;
		free_wrapper((void **)&dt.var_name);
		dt.token_str = tkn->value;
		if (tkn->type == TOKEN_HEREDOC)
		{
			tkn = next;
			next = tkn->next;
			continue ;
		}
		if (1 == is_expandable(*tkn, &dt, shell))
			continue ;
		if (wrap_assamble_expansion(&tkn, &dt) == FALSE)
			return (1);
		next = head;
	}
	return (free_wrapper((void **)&dt.var_name), 0);
}
