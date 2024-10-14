/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:25:06 by marvin            #+#    #+#             */
/*   Updated: 2024/10/11 11:25:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		num_handler(const char *str, int *p_i)
{
	int	rendu;
	
	rendu = ft_atoi(str);
	(*p_i) += num_len(rendu) - 1;
	return (rendu);
}
