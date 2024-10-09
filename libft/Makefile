CC := cc
SRCS := ${shell find . -maxdepth 1 -name "*.c" -type f | grep -v "_bonus\.c$$"}
SRCSB := ${shell find . -maxdepth 1 -name "*_bonus.c" -type f }
OBJS := $(SRCS:.c=.o)
OBJSB := $(SRCSB:.c=.o)
CFLAGS := -Wall -Wextra -Werror
NAME := libft.a
LIBC := ar rcs
RM := rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(NAME) $(OBJSB)
	$(LIBC) $(NAME) $(OBJSB)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(bonus) 

re: fclean all

.PHONY : all clean fclean re bonus
