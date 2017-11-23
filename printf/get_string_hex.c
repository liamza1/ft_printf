/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:50:52 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 15:50:54 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_hex(t_conversion *conversion
										, va_list arguments)
{
	char			*string;
	char			*final;
	uintmax_t		value;
	t_bool			is_zero_value;

	value = get_unsigned_number_argument(conversion->length, arguments);
	if (!value && conversion->precision_set)
		string = ft_strdup("");
	else
		string = ft_basetoa(value, 16);
	if (conversion->specifier == HEX_LOWER)
		ft_strtolower(string);
	is_zero_value = string[0] == '0' || string[0] == '\0';
	add_precision_padding(conversion, &string);
	if ((conversion->flags.hashtag && !is_zero_value)
		&& !(conversion->precision_set && conversion->precision == 0))
	{
		final = ft_strjoin(conversion->specifier == HEX_LOWER ? "0x" : "0X"
							, string);
		free(string);
	}
	else
		final = string;
	return (final);
}
