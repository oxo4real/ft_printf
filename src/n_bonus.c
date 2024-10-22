/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:29:12 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 13:50:13 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>

void	n_bonus(int	*p_rendu, va_list args, int flag_data[FLAG_DATA_SIZE])
{
	int	rendu;
	int	*arg;

	arg = va_arg(args, int *);
	if (arg)
	{
		rendu = (*p_rendu);
		if (flag_data[SHORT])
			rendu = (short)rendu;
		(*arg) = rendu;
	}
}
