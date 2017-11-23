/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:34:22 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 13:34:28 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_char_and_padding(t_conversion *conversion
											, char argument, char *string
											, t_format *format)
{
	if (argument)
		ft_putstr(string);
	else
	{
		if (conversion->flags.left_justify)
			ft_putchar('\0');
		ft_putstr(string);
		if (!conversion->flags.left_justify)
			ft_putchar('\0');
		format->written++;
	}
	format->written += ft_strlen(string);
}

void				print_char(t_conversion *conversion, char argument
								, t_format *format)
{
	char			*string;

	string = ft_strnew(1);
	string[0] = argument;
	if (!argument && conversion->width)
		conversion->width--;
	add_final_padding(conversion, &string);
	print_char_and_padding(conversion, argument, string, format);
}
