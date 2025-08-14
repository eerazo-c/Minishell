/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*aux_end_str(const char *s, const char *set)
{
	size_t	len;

	len = ft_strlen(s);
	while (s[len - 1] && len && ft_strchr(set, s[len - 1]))
		len--;
	return ((char *)s + len - 1);
}

// WARNING:: malloc
char	*ft_strtrim(const char *s, const char *set)
{
	size_t	size;
	char	*end_str;

	end_str = NULL;
	if (!s)
		return (ft_strdup(""));
	while (ft_strchr(set, *s) && *s)
		s++;
	if (*s)
		end_str = aux_end_str(s, set);
	else
		return (ft_strdup(""));
	size = end_str - s + 1;
	return (ft_substr(s, 0, size));
}
