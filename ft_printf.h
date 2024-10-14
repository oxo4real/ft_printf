#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define WIDTH 0
# define PRECISION 1
# define LEFT_JUSTIFIED 2
# define ZERO_PADDING 3
# define IS_PRECISION 4
# define HASH 5
# define PLUS 6
# define SPACE 7

# define FLAG_DATA_SIZE 8

int		ft_printf(const char *format, ...);
void	format_handler(const char *p_format, int *p_i, int *p_rendu, va_list args);
void	flag_handler(const char *p_format, int *p_i, int flag_data[FLAG_DATA_SIZE], va_list args);
void	printer(char conversion, int *p_rendu, int flag_data[FLAG_DATA_SIZE], va_list args);
int		num_handler(const char *str, int *p_i);
int		num_len(long long num);
void	char_printer(char c, int flag_data[FLAG_DATA_SIZE], int *p_rendu);
void	str_printer(char *str, int flag_data[FLAG_DATA_SIZE], int *p_rendu);
void	int_printer(int num, int flag_data[FLAG_DATA_SIZE], int *p_rendu);
void	uint_printer(unsigned int un, int flag_data[FLAG_DATA_SIZE], int *p_rendu);
void	hex_printer(unsigned long long num, int flag_data[FLAG_DATA_SIZE], int *p_rendu, char conversion);
void	pointer_printer(unsigned long long ln, int flag_data[FLAG_DATA_SIZE], int *p_rendu);
void	padding_printer(char c, int len, int *p_rendu);
int		hex_len(unsigned long long num);

#endif