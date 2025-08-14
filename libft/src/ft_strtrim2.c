/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// WARNING:: malloc
char	*ft_strtrim2(const char *str, const char *set)
{
	size_t	size;
	char	*end_str;

	end_str = NULL;
	if (NULL == str)
		return (ft_strdup(""));
	while (ft_strchr(set, *str) && *str != '\0')
		str++;
	if (*str == '\0')
		return (ft_strdup(""));
	size = 0;
	while (str[size] != '\0' && ft_strchr(set, str[size]) == NULL)
		size++;
	end_str = ft_substr(str, 0, size);
	return (end_str);
}
