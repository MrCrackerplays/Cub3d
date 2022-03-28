SHELL = bash

BONUS_NAME = cub3d_bonus

MINILIBX_FOLDER ?= MLX42
MINILIBX_FILE ?= $(MINILIBX_FOLDER)/libmlx42.a

LIBFT_FOLDER ?= libft
LIBFT_FILE ?= $(LIBFT_FOLDER)/libft.a

OBJECTS := \
	map/format.o \
	map/get_at.o \
	map/validate.o \
	mlx/color.o \
	mlx/color_info.o \
	mlx/draw_box.o \
	mlx/draw_line.o \
	mlx/draw_pixel.o \
	mlx/get_color_at.o \
	utils/find_angle.o \
	utils/ray_angle_fix.o \
	utils/skip_space.o \
	utils/test_access.o

ifdef BONUS
NAME := $(BONUS_NAME)
HEADER_FILES := cub3d_bonus.h
OBJECTS := ${OBJECTS} \
	bonus/game/ceiling_bonus.o \
	bonus/game/init_bonus.o \
	bonus/game/main_bonus.o \
	bonus/game/map_rendering_bonus.o \
	bonus/game/minimap_bonus.o \
	bonus/game/mirror_bonus.o \
	bonus/game/sprite_bonus.o \
	bonus/game/player_collision_bonus.o \
	bonus/game/player_bonus.o \
	bonus/game/ray_casting_bonus.o \
	bonus/game/sprite_draw_bonus.o \
	bonus/game/sprite_new_bonus.o \
	bonus/map/format_u_bonus.o \
	bonus/map/import_bonus.o \
	bonus/map/populate_bonus.o \
	bonus/mlx/draw_pixel_bonus.o \
	bonus/utils/wall_types_bonus.o
else
NAME := cub3d
HEADER_FILES := cub3d.h
OBJECTS := ${OBJECTS} \
	game/init.o \
	game/main.o \
	game/map_rendering.o \
	game/player.o \
	game/ray_casting.o \
	map/format_u.o \
	map/import.o \
	map/populate.o \
	utils/wall_types.o
endif

OBJECT_DIR := obj
OBJECTS := $(addprefix $(OBJECT_DIR)/,$(OBJECTS))
OBJECT_DIRS := map mlx utils game
OBJECT_DIRS := $(OBJECT_DIRS) $(addprefix bonus/,$(OBJECT_DIRS))
OBJECT_DIRS := $(addprefix $(OBJECT_DIR)/,$(OBJECT_DIRS))
HEADER_FILES := $(HEADER_FILES) cub_macros.h
HEADER_FILES := $(addprefix include/,$(HEADER_FILES))
INCLUDE := include libft/include $(MINILIBX_FOLDER)/include
INCLUDE := $(addprefix -I,$(INCLUDE))

CFLAGS ?= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS := -g $(CFLAGS) -D DEBUG
endif

OBJ_FLAGS := -O3

# This should allow compilation on linux (no windows support)
OS := $(shell uname)
ifeq ($(OS),Darwin)
MLX_FLAGS := -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"
else
MLX_FLAGS := -ldl -lglfw -lm
endif

# //= Colors =// #
BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(MINILIBX_FILE) $(LIBFT_FILE) $(OBJECTS)
	@echo -n "[$(NAME)] compiling $(NAME)... "
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FILE) $(MINILIBX_FILE) -o $(NAME) $(MLX_FLAGS)
	@echo "[OK]"

obj/%.o: src/%.c $(HEADER_FILES)
	@printf "\r[$(NAME)] Compiling: $(RESET)$(BOLD)$(notdir $<)"
	@mkdir -p $(OBJECT_DIRS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_FLAGS) -c $< -o $@
	@printf "\r\e[50C$(GREEN)[OK]\n$(RESET)"

$(MINILIBX_FILE):
	@echo "[$(NAME)] compiling MLX42"
	$(MAKE) -C ./$(MINILIBX_FOLDER)
	@echo "[$(NAME)] finished compiling MLX42"

$(LIBFT_FILE):
	@echo "[$(NAME)] compiling libft"
	$(MAKE) -C ./$(LIBFT_FOLDER)
	@echo "[$(NAME)] finished compiling libft"

clean:
	@echo "[$(NAME)] cleaning $(NAME)"
	$(MAKE) clean -C ./$(LIBFT_FOLDER)
	$(MAKE) clean -C ./$(MINILIBX_FOLDER)
	@rm -rf $(OBJECT_DIR)

fclean: clean
	@echo "[$(NAME)] fully cleaning $(NAME)"
	$(MAKE) fclean -C ./$(LIBFT_FOLDER)
	$(MAKE) fclean -C ./$(MINILIBX_FOLDER)
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf obj

re: fclean all

bonus:
	$(MAKE) BONUS=1

run: all
	@echo "[$(NAME)] running $(NAME)"
	./$(NAME) maps/simple1.cub

runb: bonus
	@echo "[$(BONUS_NAME)] running $(BONUS_NAME)"
	./$(BONUS_NAME) bonus_maps/simple1.cub

run_bonus: runb

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re bonus run runb run_bonus debug
