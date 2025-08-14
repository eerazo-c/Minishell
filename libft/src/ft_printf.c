/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_data	init_data(t_data data)
{
	data.errctl = 0;
	data.lenght = 0;
	return (data);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	data;
	int		i;

	i = 0;
	data = init_data(data);
	va_start(args, str);
	while (str[i] != '\0' && data.errctl != -1)
	{
		if (str[i] != '%')
			aux_printc(str[i++], &data);
		else if (str[i] == '%')
		{
			parse_format(str[++i], &data, args);
			i++;
		}
		if (data.errctl == -1)
			return (data.errctl);
	}
	va_end(args);
	return (data.lenght);
}
