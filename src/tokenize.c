/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static t_token_type	detect_operator(char *s, int *i)
{
	if (s[*i] == '|')
		return ((*i)++, TOKEN_PIPE);
	if (s[*i] == '<' && s[*i + 1] == '<')
		return ((*i) += 2, TOKEN_HEREDOC);
	if (s[*i] == '>' && s[*i + 1] == '>')
		return ((*i) += 2, TOKEN_REDIR_APPEND);
	if (s[*i] == '<')
		return ((*i)++, TOKEN_REDIR_IN);
	if (s[*i] == '>')
		return ((*i)++, TOKEN_REDIR_OUT);
	return (TOKEN_WORD);
}

t_token	*tokenize_line(char *line)
{
	t_token			*tokens;
	t_token_type	type;
	int				i;

	tokens = NULL;
	i = 0;
	while (line && line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '\0')
			break ;
		if (line[i] != '\0' && is_special_char(line[i]))
		{
			type = detect_operator(line, &i);
			add_token(&tokens, type, NULL);
		}
		else if (line[i] != '\0')
		{
			if (collect_words(&tokens, line, &i, &type) == 1)
				return (wrapper_exit(&tokens));
		}
	}
	return (tokens);
}
