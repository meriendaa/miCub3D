/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:59 by amantara          #+#    #+#             */
/*   Updated: 2022/11/19 11:25:41 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*bakcup;
	t_list	*last;

	bakcup = *lst;
	while (bakcup)
	{
		last = bakcup->next;
		ft_lstdelone(bakcup, del);
		bakcup = last;
	}
	*lst = NULL;
}
