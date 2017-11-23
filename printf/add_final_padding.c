/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_final_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:46:38 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 15:48:05 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				get_filler_char(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros
		&& (conversion->specifier == HEX_LOWER
			|| conversion->specifier == HEX_UPPER))
		return ('0');
	return (' ');
}

void				add_final_padding(t_conversion *conversion
										, char **string)
{
	char			*new;
	char			*padding;
	intmax_t		needed;

	needed = conversion->width - ft_strlen(*string);
	if (needed > 0)
	{
		padding = ft_strnew(needed);
		ft_memset(padding, get_filler_char(conversion), needed);
		if (conversion->flags.left_justify)
			new = ft_strjoin(*string, padding);
		else
			new = ft_strjoin(padding, *string);
		free(*string);
		free(padding);
		*string = new;
	}
}
