CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := src/
SRC_FILES := char_printer.c flag_handler.c format_handler.c ft_printf.c \
			 hex_len.c hex_printer.c int_printer.c num_handler.c num_len.c \
			 padding_printer.c pointer_printer.c converter.c str_printer.c \
			 uint_printer.c flag_handler_bonus.c n_bonus.c
SRCS := ${addprefix $(SRC_DIR),$(SRC_FILES)}

BUILD_DIR := build/
OBJ_FILES := $(SRC_FILES:.c=.o)
OBJS := ${addprefix $(BUILD_DIR),$(OBJ_FILES)}

LIBFT_LIB := libft/libft.a
LIBFT_DIR := libft/
LIBFT_FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			   ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			   ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			   ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			   ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			   ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			   ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LIBFT_SRCS := ${addprefix $(LIBFT_DIR),$(LIBFT_FILES)}
LIBFT_OBJS := ${addprefix $(LIBFT_DIR),$(LIBFT_FILES:.c=.o)}

NAME := libftprintf.a

all: $(BUILD_DIR) $(NAME)

$(NAME): $(LIBFT_OBJS) $(OBJS)
	ar rcs $(NAME) $?

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB): $(LIBFT_OBJS)
	make -C $(LIBFT_DIR)
	
$(LIBFT_DIR)%.o: $(LIBFT_DIR)%.c
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY : all clean fclean re bonus
