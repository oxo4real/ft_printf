/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:15:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 13:22:59 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		rendu;
	int		i;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(args, format);
	i = 0;
	rendu = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			rendu++;
			i++;
		}
		else
		{
			i++;
			format_handler(format, &i, &rendu, args);
		}
	}
	va_end(args);
	return (rendu);
}
