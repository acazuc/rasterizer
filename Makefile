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
			color/color_add.c \
			color/color_div.c \
			color/color_mult.c \
			color/color_sub.c \
			ftg/blend/ftg_blend_color.c \
			ftg/blend/ftg_blend_equation_separate.c \
			ftg/blend/ftg_blend_equation.c \
			ftg/blend/ftg_blend_func_separate.c \
			ftg/blend/ftg_blend_func.c \
			ftg/depth/ftg_depth_func.c \
			ftg/depth/ftg_depth_mask.c \
			ftg/depth/ftg_depth_range.c \
			ftg/fog/ftg_fog_mode_color.c \
			ftg/fog/ftg_fog_start_end_index_density.c \
			ftg/fog/ftg_fog.c \
			ftg/get/ftg_get_booleanv.c \
			ftg/get/ftg_get_doublev.c \
			ftg/get/ftg_get_floatv.c \
			ftg/get/ftg_get_intv.c \
			ftg/get/ftg_get.c \
			ftg/matrix/ftg_load_identity.c \
			ftg/matrix/ftg_load_matrix.c \
			ftg/matrix/ftg_load_transpose_matrix.c \
			ftg/matrix/ftg_matrix_mode.c \
			ftg/matrix/ftg_mult_matrix.c \
			ftg/matrix/ftg_mult_transpose_matrix.c \
			ftg/matrix/ftg_perspective.c \
			ftg/matrix/ftg_rotate.c \
			ftg/matrix/ftg_scale.c \
			ftg/matrix/ftg_translate.c \
			ftg/rast/rast_line.c \
			ftg/rast/rast_pixel_put.c \
			ftg/rast/rast_triangle.c \
			ftg/rast/rast_vertex.c \
			ftg/rast/rast_watch_vertex.c \
			ftg/ftg_clear.c \
			ftg/ftg_color_pointer.c \
			ftg/ftg_ctx_init.c \
			ftg/ftg_ctx_set.c \
			ftg/ftg_disable_client_state.c \
			ftg/ftg_disable.c \
			ftg/ftg_draw_arrays_points.c \
			ftg/ftg_draw_arrays_triangles.c \
			ftg/ftg_draw_arrays.c \
			ftg/ftg_enable_client_state.c \
			ftg/ftg_enable.c \
			ftg/ftg_get_error.c \
			ftg/ftg_is_enabled.c \
			ftg/ftg_maxbsf.c \
			ftg/ftg_maxild.c \
			ftg/ftg_minbsf.c \
			ftg/ftg_minild.c \
			ftg/ftg_vertex_pointer.c \
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
	@mkdir -p $(OBJS_PATH)color
	@mkdir -p $(OBJS_PATH)ftg
	@mkdir -p $(OBJS_PATH)ftg/blend
	@mkdir -p $(OBJS_PATH)ftg/depth
	@mkdir -p $(OBJS_PATH)ftg/fog
	@mkdir -p $(OBJS_PATH)ftg/get
	@mkdir -p $(OBJS_PATH)ftg/matrix
	@mkdir -p $(OBJS_PATH)ftg/rast
	@mkdir -p $(OBJS_PATH)mat4

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
