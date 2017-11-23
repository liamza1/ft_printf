/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_number_argument.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:52:04 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 15:52:06 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_unsigned_number_argument(t_length length
												, va_list arguments)
{
	uintmax_t	value;

	if (length == L)
		return (va_arg(arguments, unsigned long));
	if (length == LL)
		return (va_arg(arguments, unsigned long long));
	if (length == J)
		return (va_arg(arguments, uintmax_t));
	if (length == Z)
		return (va_arg(arguments, size_t));
	value = va_arg(arguments, unsigned int);
	if (length == HH)
		value = (unsigned char)value;
	else if (length == H)
		value = (unsigned short)value;
	else if (length == DEFAULT_LENGTH)
		value = (unsigned int)value;
	return (value);
}
