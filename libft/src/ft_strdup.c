/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
