/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// first if - ugly but makes the program crash in case of false big
char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	small_len;

	if (big[0])
		small_len = ft_strlen(small);
	if (!*small)
		return ((char *)big);
	while (len >= small_len && *big)
	{
		if (len-- >= small_len && ft_strncmp(big, small, small_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
