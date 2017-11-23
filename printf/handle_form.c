/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_form.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:49:54 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 13:29:23 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int			check_percent_percent(t_format *format)
{
	if (*get_current(format) == '%')
	{
		ft_putchar('%');
		format->location++;
		format->written++;
		return (1);
	}
	else
		return (0);
}

static void			handle_conversion(t_format *format, va_list arguments)
{
	t_conversion	conversion;

	if (check_percent_percent(format))
		return ;
	ft_bzero(&conversion, sizeof(conversion));
	if (parse_conversion(&conversion, arguments, format) == OKAY
			&& validate_conversion(&conversion, format) == OKAY)
		print_conversion(&conversion, arguments, format);
	else if (*get_current(format) == '%')
	{
		ft_putchar('%');
		format->location++;
		format->written++;
	}
}

void				handle_format(t_format *format, va_list arguments)
{
	char			current;

	while ((current = *get_current(format)))
	{
		if (current == '%')
		{
			format->location++;
			handle_conversion(format, arguments);
		}
		else
		{
			ft_putchar(current);
			format->written++;
			format->location++;
		}
	}
}
