# Variables
NAME_SERVER = server
NAME_CLIENT = client
LIBFT_DIR = ./Libft
FT_PRINTF_DIR = ./printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files for server and client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Rules
all: $(LIBFT) $(FT_PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

# Build server
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME_SERVER)

# Build client
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME_CLIENT)

# Build libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf library
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean everything (including compiled libraries and binaries)
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re