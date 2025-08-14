/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// 
char	*ft_substr(const char *ptr, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!ptr)
		return (NULL);
	s_len = ft_strlen(ptr);
	if (s_len < (size_t)start || !len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && ptr[i + start])
	{
		str[i] = ptr[i + start];
		i++;
	}
	return (str);
}
