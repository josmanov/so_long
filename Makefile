# VARIABLES
NAME            = so_long
LIBFT           = libft/libft.a
MLX_PATH        = MLX42
SRC_DIR         = src
BONUS_DIR       = bonus/src
OBJ_DIR         = obj
BONUS_OBJ_DIR   = bonus/obj

# Mandatory source files
SRC = main.c map_config.c valid_map.c valid_map_extra.c \
      image_config.c control_config.c utils.c error.c \
      draw_map.c draw_player.c collectible.c control_keys.c

# Bonus source files
BONUS_SRC = main_bonus.c map_config_bonus.c valid_map_bonus.c valid_map_extra_bonus.c\
            image_config_bonus.c control_config_bonus.c utils_bonus.c error_bonus.c \
            draw_map_bonus.c draw_player_bonus.c collectible_bonus.c control_keys_bonus.c \
            animate_collectibles_bonus.c enemy_control_config_bonus.c enemy_init_bonus.c \
            game_loop_bonus.c

# Object files
OBJ             = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
BONUS_OBJ       = $(addprefix $(BONUS_OBJ_DIR)/,$(BONUS_SRC:.c=.o))

# Compiler and flags
CC              = cc
CFLAGS          = -g -Wall -Wextra -Werror
MLX_FLAGS       = -I includes -I $(MLX_PATH)/include
LIBS            = $(MLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)

# MLX42 repository URL
REPO_URL        = https://github.com/codam-coding-college/MLX42.git

# COLORS
RED     = \033[1;31m
GREEN   = \033[1;32m
BLUE    = \033[1;34m
RESET   = \033[0m

# TARGETS
# Default target (mandatory)
all: libft mlx $(NAME) success_all

# Bonus target
bonus: libft mlx $(NAME)_bonus success_bonus

# LIBFT
# Build libft
libft:
	@make -s -C libft

# MLX42
# Build MLX42
mlx:
	@if [ ! -d "$(MLX_PATH)" ]; then \
			echo "$(RED)\nMLX42 repository not found\n$(RESET)"; \
			echo "$(BLUE)Cloning MLX42 repository...\n$(RESET)"; \
			git clone $(REPO_URL) $(MLX_PATH); \
			else \
			echo "$(GREEN)\nMLX42 repository found\n$(RED)MLX42 cloning cancelled$(RESET)"; \
		fi
	@if [ ! -d "$(MLX_PATH)/build" ]; then \
			echo "$(BLUE)\nBuilding MLX42..$(RESET)"; \
			cmake $(MLX_PATH) -B $(MLX_PATH)/build; \
		fi
	@make -s -C $(MLX_PATH)/build -j4

# COMPILATION
# Compile mandatory source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

# Compile bonus source files into object files
$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(BONUS_OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

# DIRECTORIES
# Create obj and obj_bonus directories if they don't exist
$(OBJ_DIR):
	@mkdir -p $@

$(BONUS_OBJ_DIR):
	@mkdir -p $@

# LINKING
# Link final executable (mandatory)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@

# Link final executable (bonus)
$(NAME)_bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBS) -o $@

# CLEANING
# Clean object files
clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@make -C libft clean

# Full clean (object files and executables)
fclean: clean
	@rm -f $(NAME) $(NAME)_bonus
	@make -C libft fclean
	@rm -rf $(MLX_PATH)

# Rebuild the project
re: fclean all

# SUCCESS MESSAGES
success_all:
		@echo "\n$(BLUE)  .▄▄ ·           ▄▄▌         ▐ ▄  ▄▄ • $(RESET)"
		@echo "$(BLUE)  ▐█ ▀. ▪         ██•  ▪     •█▌▐█▐█ ▀ ▪$(RESET)"
		@echo "$(BLUE)  ▄▀▀▀█▄ ▄█▀▄     ██▪   ▄█▀▄ ▐█▐▐▌▄█ ▀█▄$(RESET)"
		@echo "$(BLUE)  ▐█▄▪▐█▐█▌.▐▌    ▐█▌▐▌▐█▌.▐▌██▐█▌▐█▄▪▐█$(RESET)"
		@echo "$(BLUE)   ▀▀▀▀  ▀█▄▀▪    .▀▀▀  ▀█▄▀▪▀▀ █▪·▀▀▀▀ $(RESET)"
		@echo "$(BLUE)*-----------------------------------------------*$(BLUE)"
		@echo "$(BLUE)| $(RESET)To run the mandatory version of so_long, use: $(BLUE)|$(RESET)"
		@echo "$(BLUE)| $(RESET)$(GREEN)./so_long $(RESET)$(WHITE) ./maps/valid_maps/(map name).ber   $(BLUE)|"
		@echo "$(BLUE)*-----------------------------------------------*$(RESET)"
		@echo "$(BLUE)| $(RESET)To build the bonus version, run: make bonus  $(BLUE) |$(RESET)"
		@echo "$(BLUE)*-----------------------------------------------*$(RESET)"

# Print success message after 'make bonus'
success_bonus:
		@echo "\n$(BLUE).▄▄ ·           ▄▄▌         ▐ ▄  ▄▄ •                              $(RESET)"
		@echo "$(BLUE)▐█ ▀. ▪         ██•  ▪     •█▌▐█▐█ ▀ ▪                             $(RESET)"
		@echo "$(BLUE)▄▀▀▀█▄ ▄█▀▄     ██▪   ▄█▀▄ ▐█▐▐▌▄█ ▀█▄                             $(RESET)"
		@echo "$(BLUE)▐█▄▪▐█▐█▌.▐▌    ▐█▌▐▌▐█▌.▐▌██▐█▌▐█▄▪▐█                             $(RESET)"
		@echo "$(BLUE) ▀▀▀▀  ▀█▄▀▪    .▀▀▀  ▀█▄▀▪▀▀ █▪·▀▀▀▀                              $(RESET)"
		@echo "$(GREEN)▄▄▄▄·        ▐ ▄ ▄• ▄▌.▄▄ ·      ▌ ▐·▄▄▄ .▄▄▄  .▄▄ · ▪         ▐ ▄  $(RESET)"
		@echo "$(GREEN)▐█ ▀█▪▪     •█▌▐██▪██▌▐█ ▀.     ▪█·█▌▀▄.▀·▀▄ █·▐█ ▀. ██ ▪     •█▌▐█ $(RESET)"
		@echo "$(GREEN)▐█▀▀█▄ ▄█▀▄ ▐█▐▐▌█▌▐█▌▄▀▀▀█▄    ▐█▐█•▐▀▀▪▄▐▀▀▄ ▄▀▀▀█▄▐█· ▄█▀▄ ▐█▐▐▌ $(RESET)"
		@echo "$(GREEN)██▄▪▐█▐█▌.▐▌██▐█▌▐█▄█▌▐█▄▪▐█     ███ ▐█▄▄▌▐█•█▌▐█▄▪▐█▐█▌▐█▌.▐▌██▐█▌ $(RESET)"
		@echo "$(GREEN)·▀▀▀▀  ▀█▄▀▪▀▀ █▪ ▀▀▀  ▀▀▀▀     . ▀   ▀▀▀ .▀  ▀ ▀▀▀▀ ▀▀▀ ▀█▄▀▪▀▀ █▪ $(RESET)"
		@echo "$(BLUE)*----------------------------------------------------*$(BLUE)"
		@echo "$(BLUE)| $(RESET)To run the bonus version of so_long, use:          $(BLUE)|$(RESET)"
		@echo "$(BLUE)| $(RESET)$(GREEN)./so_long_bonus $(RESET)$(WHITE) ./bonus/maps_bonus/(map name).ber $(BLUE)|"
		@echo "$(BLUE)*----------------------------------------------------*$(RESET)"
		@echo "$(BLUE)| $(RESET)To build the mandatory version, run: make         $(BLUE) |$(RESET)"
		@echo "$(BLUE)*----------------------------------------------------*$(RESET)"
# PHONY TARGETS
.PHONY: all bonus libft mlx clean fclean re

