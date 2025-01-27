# **************************************************************************** #
#                                COMPILER RULES                                #
# **************************************************************************** #

NAME		= so_long
LIBFT		= libft/libft.a
MLX_PATH	= MLX42
SRC_DIR		= src
OBJ_DIR		= obj

# Mandatory source files
SRC = main.c map_config.c valid_map.c valid_map_extra.c \
      image_config.c animate_collectibles.c control_config.c \
      enemy_control_config.c enemy_init.c \
      utils.c game_loop.c error.c draw_map.c draw_player.c \
	  collectible.c control_keys.c

# Bonus source files (if any)
BONUS_SRC	= 

# Object files
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
BONUS_OBJ	= $(addprefix $(OBJ_DIR)/,$(BONUS_SRC:.c=.o))

# Compiler and flags
CC			= cc
CFLAGS		= -g -Wall -Wextra -Werror
MLX_FLAGS	= -I includes -I $(MLX_PATH)/include
LIBS		= $(MLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)

# MLX42 repository URL
REPO_URL	= https://github.com/codam-coding-college/MLX42.git

# Default target
all: libft mlx $(NAME)

# Bonus target
bonus: all

# Build libft
libft:
	@make -C libft

# Build MLX42
mlx:
	@if [ ! -d "$(MLX_PATH)" ]; then \
		git clone $(REPO_URL) $(MLX_PATH); \
	fi
	@if [ ! -d "$(MLX_PATH)/build" ]; then \
		cmake $(MLX_PATH) -B $(MLX_PATH)/build; \
	fi
	@make -C $(MLX_PATH)/build -j4

# Link final executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $@

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

# Full clean (object files and executable)
fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all bonus libft mlx clean fclean re
