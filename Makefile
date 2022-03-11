NAME := cub3d

MINILIBX_FOLDER ?= MLX42
MINILIBX_FILE ?= $(MINILIBX_FOLDER)/libmlx42.a

LIBFT_FOLDER ?= libft
LIBFT_FILE ?= $(LIBFT_FOLDER)/libft.a

OBJECTS := \
	game/init.o \
	game/main.o \
	game/map_rendering.o \
	game/minimap_bonus.o \
	game/player.o \
	game/ray_casting.o \
	game/mirror_bonus.o \
	game/ceiling_bonus.o \
	game/sprite_bonus.o \
	mlx/color.o \
	mlx/color_info.o \
	mlx/draw_box.o \
	mlx/draw_line.o \
	mlx/draw_pixel.o \
	mlx/get_color_at.o \
	utils/find_angle.o \
	utils/wall_types_bonus.o \
	utils/skip_space.o \
	utils/test_access.o \
	utils/sprite_new.o \
	utils/ray_angle_fix.o \
	map/get_at.o \
	map/format.o \
	map/import.o \
	map/validate.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
OBJECT_DIRS := map mlx utils game
OBJECT_DIRS := $(addprefix obj/,$(OBJECT_DIRS))
HEADER_FILES := cub3d.h
HEADER_FILES := $(addprefix include/,$(HEADER_FILES))
INCLUDE := include libft/include $(MINILIBX_FOLDER)/include
INCLUDE := $(addprefix -I,$(INCLUDE))

CFLAGS ?= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS := -g $(CFLAGS)
endif

OBJ_FLAGS := -O3

# This should allow compilation on linux (no windows support)
OS := $(shell uname)
ifeq ($(OS),Darwin)
MLX_FLAGS := -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"
else
MLX_FLAGS := -ldl -lglfw -lm
endif

all: $(NAME)

$(NAME): $(MINILIBX_FILE) $(LIBFT_FILE) $(OBJECTS)
	@/bin/echo -n "[$(NAME)] compiling $(NAME)... "
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FILE) $(MINILIBX_FILE) -o $(NAME) $(MLX_FLAGS)
	@echo "[OK]"

obj/%.o: src/%.c $(HEADER_FILES)
	@/bin/echo -n "[$(NAME)] compiling $@... "
	@mkdir -p $(OBJECT_DIRS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_FLAGS) -c $< -o $@
	@echo "[OK]"

$(MINILIBX_FOLDER)/Makefile:
	@echo "[$(NAME)] MLX42 not detected, cloning MLX42"
	git clone -b Norme https://github.com/W2Codam/MLX42.git $(MINILIBX_FOLDER)

$(MINILIBX_FILE): $(MINILIBX_FOLDER)/Makefile
	@echo "[$(NAME)] pulling MLX42 updates"
	cd $(MINILIBX_FOLDER)
	git pull
	cd ..
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
	@rm -f $(OBJECTS)

fclean: clean
	@echo "[$(NAME)] fully cleaning $(NAME)"
	$(MAKE) fclean -C ./$(LIBFT_FOLDER)
	$(MAKE) fclean -C ./$(MINILIBX_FOLDER)
	@rm -f $(NAME)
	@rm -rf obj

re: fclean all

bonus: all

run: all
	@echo "[$(NAME)] running $(NAME)"
	./$(NAME) maps/simple1.cub

debug:
	$(MAKE) DEBUG=1

runl: $(MINILIBX_FILE) $(LIBFT_FILE)
	gcc \
		src/game/* src/map/* src/mlx/* src/utils/* \
		libft/libft.a MLX42/libmlx42.a -ldl -lglfw -lm -I include -I libft/include -I MLX42/include

.PHONY: all clean fclean re bonus run debug
