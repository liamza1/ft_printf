/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:51:32 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 15:51:34 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_pointer(t_conversion *conversion
											, va_list arguments)
{
	char			*before;
	char			*string;
	long			value;

	value = (long)va_arg(arguments, void*);
	if (value == 0)
		return (ft_strdup("0x0"));
	before = ft_basetoa(value, 16);
	ft_strtolower(before);
	string = ft_strjoin("0x", before);
	free(before);
	(void)conversion;
	(void)arguments;
	return (string);
}
