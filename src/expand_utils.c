/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_expand(t_expand *dt)
{
	dt->token_str = NULL;
	dt->to_expand = NULL;
	dt->matching_env = NULL;
	dt->var_name = NULL;
	dt->false_env = 0;
}

int	aux_upd_data(t_expand *dt, char *match, char *var_name, char *env_var)
{
	dt->matching_env = env_var;
	dt->to_expand = match;
	dt->var_name = var_name;
	return (1);
}

int	wrap_assamble_expansion(t_token **tkn, t_expand *dt)
{
	char	*tmp;

	tmp = NULL;
	tmp = assemble_expansion((*tkn)->value, dt);
	if (NULL == tmp)
		return (perror("cant expand variable\n"), FALSE);
	free((*tkn)->value);
	(*tkn)->value = tmp;
	return (TRUE);
}
