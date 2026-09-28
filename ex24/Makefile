NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC_DIR = srcs
SRCS = $(SRC_DIR)/ft_putchar.c \
       $(SRC_DIR)/ft_swap.c \
       $(SRC_DIR)/ft_putstr.c \
       $(SRC_DIR)/ft_strlen.c \
       $(SRC_DIR)/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

