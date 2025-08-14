/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// cast the int as char? to check at campus. Allows extended ascii, should error
char	*ft_strchr(const char *str, char c)
{
	char	*ref;

	ref = (char *)str;
	while (*ref && *ref != (char) c)
		ref++;
	if (*ref == (char) c)
		return (ref);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s1 = "abcdef";
	char *s2;

	s2 = ft_strchr(s1, '\0');
	printf("find	%s\nindex	%zu\n", s2, s2 - s1);
	return (0);
}*/
