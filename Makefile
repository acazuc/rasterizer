# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/12/30 18:10:43 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rasterizer

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast -g -march=native -flto -mtune=native -funroll-loops

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
			mat4/mat4_clear.c \
			mat4/mat4_init_scale.c \
			mat4/mat4_init_identity.c \
			mat4/mat4_init_translation.c \
			mat4/mat4_init_rotations.c \
			mat4/mat4_init_projection.c \
			mat4/mat4_mult.c \
			mat4/mat4_transform_vec4.c \
			mat4/mat4_reverse.c \
			mat4/mat4_dump.c \
			render_resize.c \
			render_render.c \
			render_set_pixel.c \
			render_put_pixel.c \
			render_render_vertex.c \
			render_render_line.c \
			render_render_triangle.c \
			render_set_zindex.c \
			render_get_zindex.c \
			camera_watch_vec4.c \
			camera_set_position.c \
			camera_set_rotation.c \
			camera_set_projection.c \
			epoch_millis.c \
			ftg/ftg_blend_func_separate.c \
			ftg/ftg_blend_func.c \
			ftg/ftg_clear.c \
			ftg/ftg_ctx_init.c \
			ftg/ftg_depth_func.c \
			ftg/ftg_depth_mask.c \
			ftg/ftg_depth_range.c \
			ftg/ftg_disable.c \
			ftg/ftg_enable.c \
			ftg/ftg_get_booleanv.c \
			ftg/ftg_get_doublev.c \
			ftg/ftg_get_error.c \
			ftg/ftg_get_floatv.c \
			ftg/ftg_get_intv.c \
			ftg/ftg_get.c \
			ftg/ftg_load_identity.c \
			ftg/ftg_load_matrix.c \
			ftg/ftg_load_transpose_matrix.c \
			ftg/ftg_matrix_mode.c \
			ftg/ftg_maxbsf.c \
			ftg/ftg_maxild.c \
			ftg/ftg_minbsf.c \
			ftg/ftg_minild.c \
			ftg/ftg_mult_matrix.c \
			ftg/ftg_mult_transpose_matrix.c \
			ftg/ftg_perspective.c \
			ftg/ftg_rotate.c \
			ftg/ftg_scale.c \
			ftg/ftg_translate.c \
			ftg/ftg_viewport.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft -lft
LIBRARY+= -L glfw/src -lglfw3

#FRAMEWORK = -framework OpenGL
#FRAMEWORK+= -framework AppKit
#FRAMEWORK+= -framework IOKit
#FRAMEWORK+= -framework CoreVideo

FRAMEWORK = -lGL
FRAMEWORK+= -lX11
FRAMEWORK+= -lXrandr
FRAMEWORK+= -lXinerama
FRAMEWORK+= -lXcursor
FRAMEWORK+= -lXxf86vm
FRAMEWORK+= -ldl
FRAMEWORK+= -lrt
FRAMEWORK+= -lm
FRAMEWORK+= -lpthread

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
	@mkdir -p $(OBJS_PATH)mat4
	@mkdir -p $(OBJS_PATH)ftg

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
