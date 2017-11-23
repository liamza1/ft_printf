/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_justify_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:15:15 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:34:04 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_justify_right(char *string
											, size_t total
											, char fill)
{
	size_t			length;
	size_t			i;

	length = ft_strlen(string);
	i = 0;
	while (i + length < total)
	{
		ft_putchar(fill);
		i++;
	}
	ft_putstr(string);
}
