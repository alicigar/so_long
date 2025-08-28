NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilib/libft -Ilib/minilibx
SRCS = src/init.c \
src/main.c \
src/map_io.c \
src/parsing.c \
src/path_parsing.c \
src/render.c \
src/events.c \
src/free.c 
OBJS = $(SRCS:.c=.o)
LIBFT = lib/libft/libft.a
MLX_DIR = lib/minilibx
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C lib/libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C lib/libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/libft

re: fclean all

.PHONY: all clean fclean re
