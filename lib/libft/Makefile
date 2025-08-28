NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strchr.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_memset.c ft_putnbr_fd.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_atoi.c ft_memmove.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strtrim.c ft_striteri.c ft_strmapi.c ft_strjoin.c ft_itoa.c ft_split.c 

SRCS_FT_PRINTF = ft_printf.c ft_print_c.c ft_print_s.c ft_print_dec.c \
ft_print_u.c ft_print_ptr.c ft_print_hexa.c ft_print_hexacaps.c 
SRCS_GNL = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_PRINTF = $(SRCS_FT_PRINTF:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	ar rcs $(NAME) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
