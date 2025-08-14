/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ref;

	ref = (char *)str;
	while (*ref)
		ref++;
	while (*ref != (char) c && ref > str)
		ref--;
	if (*ref == (char) c)
		return (ref);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "";
	char	*s2;

	s2 = ft_strrchr(s1, 'a');
	printf("find	%s\nindex	%zu\n", s2, s2 - s1);
	return (0);
}*/
