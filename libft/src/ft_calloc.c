/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// dont use freakin macros for dumb reasons aggg
void	*ft_calloc(size_t blocks, size_t sizeoftype)
{
	void	*ptr;

	ptr = malloc(sizeoftype * (blocks));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, blocks * sizeoftype);
	return (ptr);
}
