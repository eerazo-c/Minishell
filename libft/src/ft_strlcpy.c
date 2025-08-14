/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *source, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen((char *)source);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && i < src_len)
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
