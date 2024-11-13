/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:51:02 by aaghzal           #+#    #+#             */
/*   Updated: 2024/11/13 11:54:15 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define WIDTH 0
# define PRECISION 1
# define LEFT_JUSTIFIED 2
# define ZERO_PADDING 3
# define IS_PRECISION 4
# define HASH 5
# define PLUS 6
# define SPACE 7

# define FLAG_DATA_SIZE 8

void	flag_handler_bonus(const char *p_format,
			int *p_i, int flag_data[FLAG_DATA_SIZE]);

#endif