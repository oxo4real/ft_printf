/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:05:30 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 10:55:31 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pointer_printer(unsigned long long ln,
			int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	flag_data[HASH] = 1;
	hex_printer(ln, flag_data, p_rendu, 'p');
}
