/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//function helps checking for changes in a string with printf:
//unsigned int for index
//char for specific char before/after change
#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;
	size_t	str_len;

	if (!s || !f)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s);
	result = ft_calloc(sizeof(char) * (str_len + 1), 1);
	if (!result)
		return (NULL);
	while (i < str_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

char	aux_ft(unsigned int a, char b)
{
	printf("i/s	%d	%c\n", a, b);
	return (b);
}

int	main(void)
{
	char	*str = "test";
	char	*dst;

	dst = ft_strmapi(str, aux_ft);
	free(dst);
	return (0);
}*/
