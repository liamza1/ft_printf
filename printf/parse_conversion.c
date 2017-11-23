/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:29:41 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 15:55:43 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					parse_conversion(t_conversion *conversion
		, va_list arguments
		, t_format *format)
{
	if (parse_flags(conversion, format) == OKAY
			&& parse_width(conversion, arguments, format) == OKAY
			&& parse_precision(conversion, arguments, format) == OKAY
			&& parse_length(conversion, format) == OKAY
			&& parse_specifier(conversion, format) == OKAY)
		return (OKAY);
	return (ERROR);
}
