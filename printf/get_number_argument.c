/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_argument.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:50:09 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 15:50:11 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		get_number_argument(t_length length, va_list arguments)
{
	intmax_t	value;

	if (length == L)
		return (va_arg(arguments, long));
	if (length == LL)
		return (va_arg(arguments, long long));
	if (length == J)
		return (va_arg(arguments, intmax_t));
	if (length == Z)
		return (va_arg(arguments, size_t));
	value = va_arg(arguments, int);
	if (length == HH)
		value = (char)value;
	else if (length == H)
		value = (short)value;
	else if (length == DEFAULT_LENGTH)
		value = (int)value;
	return (value);
}
