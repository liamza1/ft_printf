/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:42:58 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 10:46:49 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format_string, ...)
{
	va_list		arguments;
	t_format	format;

	if (!format_string)
	{
		ft_putendl_fd("ft_prinf: format string must be valid", 2);
		exit(1);
	}
	ft_bzero(&format, sizeof(t_format));
	format.string = format_string;
	va_start(arguments, format_string);
	handle_format(&format, arguments);
	va_end(arguments);
	return (format.written);
}
