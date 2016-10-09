# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/10/09 12:26:14 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rasterizer

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast -g

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = main.c \
			error_quit.c \
			window_create.c \
			window_update_context.c \
			window_listener_resize.c \
			color_add.c \
			color_sub.c \
			color_mult.c \
			mat4_clear.c \
			mat4_init_identity.c \
			mat4_init_translation.c \
			mat4_init_rotations.c \
			mat4_init_projection.c \
			mat4_mult.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft -lft
LIBRARY+= -L glfw/src -lglfw3

FRAMEWORK = -framework OpenGL
FRAMEWORK+= -framework AppKit
FRAMEWORK+= -framework IOKit
FRAMEWORK+= -framework CoreVideo

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) $(FRAMEWORK)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
