/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags_ignored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:37:26 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 13:37:29 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				begin_blank_show_sign(t_conversion *conversion
											, t_format *format)
{
	if (conversion->flags.positive_values_begin_blank
		&& conversion->flags.show_sign)
	{
		ft_putendl_fd("flag ' ' is ignored when flag '+' is present", 2);
		print_format_error(format);
		conversion->flags.positive_values_begin_blank = 0;
	}
}

void				pad_zeros_general(t_conversion *conversion
											, t_format *format)
{
	if (conversion->flags.pad_with_zeros)
	{
		if (conversion->flags.left_justify)
		{
			ft_putendl_fd("flag '0' is ignored when flag '-' is present", 2);
			print_format_error(format);
			conversion->flags.pad_with_zeros = 0;
		}
		else if (conversion->precision_set)
		{
			ft_putstr_fd("flag '0' is ignored with precision and %", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putchar_fd('\n', 2);
			print_format_error(format);
			conversion->flags.pad_with_zeros = 0;
		}
	}
}

void				validate_flags_ignored(t_conversion *conversion
											, t_format *format)
{
	begin_blank_show_sign(conversion, format);
	pad_zeros_general(conversion, format);
}
