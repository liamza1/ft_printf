/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:51:16 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 15:51:18 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_octal(t_conversion *conversion
										, va_list arguments)
{
	char			*string;
	char			*final;
	uintmax_t		value;

	value = get_unsigned_number_argument(conversion->length, arguments);
	if (!value && conversion->precision_set)
		string = ft_strdup("");
	else
		string = ft_basetoa(value, 8);
	add_precision_padding(conversion, &string);
	if (conversion->flags.hashtag && string[0] != '0')
	{
		final = ft_strjoin("0", string);
		free(string);
	}
	else
		final = string;
	return (final);
}
