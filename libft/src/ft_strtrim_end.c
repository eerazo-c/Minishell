/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	aux_end_str(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (ft_strchr(set, s[i]))
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim_end(const char *str, const char *set)
{
	size_t	size;
	char	*new;

	if (NULL == str)
		return (ft_strdup(""));
	if (*str == '\0')
		return (ft_strdup(""));
	size = aux_end_str(str, set);
	new = ft_substr(str, 0, size);
	return (new);
}
