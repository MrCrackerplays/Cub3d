NAME := cub3d

MINILIBX_FOLDER ?= MLX42
MINILIBX_FILE ?= $(MINILIBX_FOLDER)/libmlx42.a

LIBFT_FOLDER ?= libft
LIBFT_FILE ?= $(LIBFT_FOLDER)/libft.a

OBJECTS := \
	mlx/mlx.o \
	mlx/color.o \
	mlx/color_info.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
HEADER_FILES := map.h
HEADER_FILES := $(addprefix include/,$(HEADER_FILES))
INCLUDE := include libft/include $(MINILIBX_FOLDER)/include/MLX42
INCLUDE := $(addprefix -I,$(INCLUDE))

CFLAGS ?= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS := -g $(CFLAGS)
endif

MLX_FLAGS := -L$(MINILIBX_FOLDER) -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"
OBJ_FLAGS := -O3

all: $(NAME)

$(NAME): $(MINILIBX_FILE) $(LIBFT_FILE) $(OBJECTS)
	@/bin/echo -n "[$(NAME)] compiling $(NAME)... "
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FILE) $(MINILIBX_FILE) -o $(NAME) $(MLX_FLAGS)
	@echo "[OK]"

obj/%.o: src/%.c $(HEADER_FILES)
	@/bin/echo -n "[$(NAME)] compiling $@... "
	@mkdir -p obj obj/map obj/mlx
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_FLAGS) -c $< -o $@
	@echo "[OK]"

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
	./$(NAME) maps/example.cub

runm: $(MINILIBX_FILE) $(LIBFT_FILE)
	gcc src/game/* src/utils/* src/mlx/* MLX42/libmlx42.a libft/libft.a -I include -I \
	libft/include -I MLX42/include $(MLX_FLAGS) -lm && ./a.out && rm a.out

runl: $(MINILIBX_FILE) $(LIBFT_FILE)
	gcc src/game/* src/utils/* src/mlx/* MLX42/libmlx42.a libft/libft.a -I include -I \
	libft/include -I MLX42/include -ldl -lglfw -lm && ./a.out && rm a.out

debug:
	$(MAKE) DEBUG=1

pull-submodules:
	git submodule init
	git submodule update

.PHONY: all clean fclean re bonus run debug runl runm pull-submodules
