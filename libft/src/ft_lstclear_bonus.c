/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// in freakin o(1) yeah babe
// the while works even tho we aint iterating since we are deleting list
// elements one by one
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*fwd;

	while (*lst)
	{
		fwd = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = fwd;
	}
	*lst = NULL;
}
