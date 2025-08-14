/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// This function expresses the invention of long. No need to hardcode the case,
// use a temporal data type which can handle edge cases, making both ints and
// edge cases adjust based on hardware
void	ft_putnbr_fd(int nb, int fd)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr / 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
/*
#include <limits.h>

int	main(void)
{
	ft_putnbr_fd(123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MAX, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar_fd('\n', 1);
}*/
