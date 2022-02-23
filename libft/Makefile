# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rdrazsky <rdrazsky@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/04 13:52:48 by rdrazsky      #+#    #+#                  #
#    Updated: 2022/02/23 15:17:22 by pdruart       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = include
FLAGS = -Wall -Wextra -Werror
FILES = \
	source/memory/malloc \
	source/memory/free \
	source/memory/free_null \
	source/list/add \
	source/list/new \
	source/list/to_array \
	source/list/_true_index \
	source/list/reverse \
	source/list/insert \
	source/list/_find_node_with_item \
	source/list/free \
	source/list/new_from_array \
	source/list/remove_at \
	source/list/replace_at \
	source/list/_node_at \
	source/list/find_index \
	source/list/pop \
	source/list/remove \
	source/list/_print \
	source/list/item_at \
	source/math/minmax \
	source/math/abs \
	source/math/true_index \
	source/file/rw \
	source/file/to_list \
	source/file/next_line \
	source/file/read_fd \
	source/file/tmp_open \
	source/file/open \
	source/file/tmp_rw \
	source/string/_new_formated \
	source/string/new \
	source/string/new_i \
	source/string/split \
	source/string/insert \
	source/string/_new \
	source/string/strip \
	source/string/free \
	source/string/cat_to \
	source/string/copy_to \
	source/string/cut \
	source/string/new_u \
	source/string/new_formated \
	source/hash_map/new \
	source/hash_map/hash \
	source/hash_map/free \
	source/hash_map/get \
	source/hash_map/remove \
	source/hash_map/set \
	source/print/_formated \
	source/print/nl \
	source/print/a \
	source/print/m \
	source/print/u \
	source/print/i \
	source/print/s \
	source/print/x \
	source/print/formated \
	source/print/c \
	source/int/int_limits \
	source/is/isalnum \
	source/is/isdigit \
	source/is/isalpha \
	source/is/isascii \
	source/is/isprint \
	source/is/isspace \
	source/exit/exit_error \
	source/cstring/strcpy \
	source/cstring/strdup \
	source/cstring/strcmp \
	source/cstring/strlen \
	source/cstring/atoi

SRC = $(foreach i, $(FILES), $(i).c)
OBJ = $(foreach i, $(FILES), $(i).o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(INCLUDE) $(DEBUG)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
