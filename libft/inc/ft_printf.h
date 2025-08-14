/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct s_data
{
	int	errctl;
	int	lenght;
}				t_data;

void	aux_printc(const char c, t_data *data);
void	aux_printstr(const char *str, t_data *data);

void	convert_nbr(int nbr, t_data *data);
void	convert_nbrbase(unsigned long nbr, char *base, int blen, t_data *data);
void	convert_ptrtoint(void *ptr, t_data *data);

void	parse_format(char format, t_data *data, va_list args);
int		ft_printf(const char *str, ...);

#endif
