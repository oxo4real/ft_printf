/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:03:45 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 11:47:05 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	padding_printer(char c, int len, int *p_rendu)
{
	while (len > 0)
	{
		ft_putchar_fd(c, 1);
		(*p_rendu) += 1;
		len--;
	}
}
