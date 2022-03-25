# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rdrazsky <rdrazsky@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/04 13:52:48 by rdrazsky      #+#    #+#                  #
#    Updated: 2022/03/25 16:27:29 by rdrazsky      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = include
FLAGS = -Wall -Wextra -Werror
FILES = \
	source/cstring/atoi \
	source/cstring/strchr \
	source/cstring/strcmp \
	source/cstring/strcpy \
	source/cstring/strdup \
	source/cstring/strlen \
	source/cstring/strstr \
	source/exit/exit_error \
	source/file/next_line \
	source/file/open \
	source/file/read_fd \
	source/file/rw \
	source/file/tmp_open \
	source/file/tmp_rw \
	source/file/to_list \
	source/hash_map/free \
	source/hash_map/get \
	source/hash_map/has_key \
	source/hash_map/hash \
	source/hash_map/new \
	source/hash_map/remove \
	source/hash_map/set \
	source/int/int_limits \
	source/is/isalnum \
	source/is/isalpha \
	source/is/isascii \
	source/is/isdigit \
	source/is/isprint \
	source/is/isspace \
	source/list/_find_node_with_item \
	source/list/_node_at \
	source/list/_print \
	source/list/_true_index \
	source/list/add \
	source/list/find_index \
	source/list/free \
	source/list/insert \
	source/list/item_at \
	source/list/new \
	source/list/new_from_array \
	source/list/pop \
	source/list/remove \
	source/list/remove_at \
	source/list/replace_at \
	source/list/reverse \
	source/list/to_array \
	source/math/abs \
	source/math/minmax \
	source/math/true_index \
	source/memory/free \
	source/memory/free_null \
	source/memory/malloc \
	source/print/_formated \
	source/print/a \
	source/print/c \
	source/print/formated \
	source/print/i \
	source/print/m \
	source/print/nl \
	source/print/s \
	source/print/u \
	source/print/x \
	source/string/_new \
	source/string/_new_formated \
	source/string/cat_to \
	source/string/copy_to \
	source/string/cut \
	source/string/free \
	source/string/insert \
	source/string/new \
	source/string/new_formated \
	source/string/new_i \
	source/string/new_u \
	source/string/split \
	source/string/strip

SRC = $(foreach i, $(FILES), $(i).c)
OBJ = $(foreach i, $(FILES), $(i).o)

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

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

%.o: %.c
	@printf "$(CYAN)$(BOLD)\r[libft] Compiling: $(RESET)$(BOLD)$(notdir $<)"
	@gcc $(FLAGS) -c $< -o $@ -I $(INCLUDE)
	@printf "\r\e[45C$(GREEN)[OK]\n$(RESET)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
