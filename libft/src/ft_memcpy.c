/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;

	i = 0;
	if (!source && !dest)
		return (NULL);
	dst = (char *)dest;
	src = (char *)source;
	while (i < n)
	{
		dst[i] = (char)src[i];
		i++;
	}
	return (dst);
}
