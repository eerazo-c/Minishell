/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// lesson: if returning a ptr, stop f# iterating over pointers ffs
void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char	*dst;
	char	*src;
	size_t	i;

	i = 0;
	dst = (char *)dest;
	src = (char *)source;
	if (src == dst)
		return ((void *)source);
	if (src < dst)
		while (n--)
			dst[n] = src[n];
	else
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
