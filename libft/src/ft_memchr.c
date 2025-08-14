/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// comparaison done with signed chars
void	*ft_memchr(const void *ptr, int c, size_t n)
{
	if (n > 0)
	{
		while (--n > 0 && *(char *)ptr != (char) c)
			ptr++;
		if (*(char *) ptr == (char) c)
			return ((void *)ptr);
	}
	return (NULL);
}
