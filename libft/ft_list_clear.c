/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:38:45 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:38:49 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_destroy(t_list *list)
{
	if (list->next != NULL)
		ft_destroy(list->next);
	free(list);
}

void			ft_list_clear(t_list **begin_list)
{
	ft_destroy(*begin_list);
	*begin_list = NULL;
}
