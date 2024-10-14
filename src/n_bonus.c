/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:29:12 by marvin            #+#    #+#             */
/*   Updated: 2024/10/14 20:29:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>

void	n_bonus(int	*p_rendu, va_list args, int flag_data[FLAG_DATA_SIZE])
{
	int rendu;

	rendu = (*p_rendu);
	if (flag_data[SHORT])
		rendu = (short)rendu;
	(*va_arg(args, int *)) = rendu;
}
