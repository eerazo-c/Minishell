/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	char	*ref;
	size_t	size;

	size = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	nstr = ft_calloc(size + 1, 1);
	if (!nstr)
		return (NULL);
	ref = nstr;
	while (*s1)
		*(ref++) = *(s1++);
	while (*s2)
		*(ref++) = *(s2++);
	return (nstr);
}
