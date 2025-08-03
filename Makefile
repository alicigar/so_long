NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 
OBJS = $(SRCS:.c=.o)
LIBFT = lib/libft/libft.a
MLX_DIR = lib/minilibx
MLX = -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lm
RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
