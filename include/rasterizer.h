/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:48:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:58:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTERIZER_H
# define RASTERIZER_H

# include "../libft/include/libft.h"
# include "../glfw/include/GLFW/glfw3.h"
# include <sys/time.h>
# include <stdio.h>


# define ERROR(x) (error_quit(x, __FILE__, __LINE__))
# define MAX(x, y) ((x) < (y) ? (y) : (x))
# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define ABS(x) ((x) < 0 ? (-(x)) : x)

# define Z_MIN 0.01
# define Z_MAX 1000

typedef struct s_triangle	t_triangle;
typedef struct s_triangle_edge	t_triangle_edge;
typedef struct s_triangle_span	t_triangle_span;
typedef struct s_camera		t_camera;
typedef struct s_env		t_env;

# include "libftg.h"
# include "mat4.h"

void					error_quit(char *str, char *file, int line);
void					window_create(t_env *env);
void					window_update_context(t_env *env);
void					window_listener_resize(GLFWwindow *window, int width, int height);
void					render_resize(t_ftg_ctx *ctx, int width, int height);
void					render_render(t_ftg_ctx *ctx);
void					render_put_pixel(t_ftg_ctx *ctx, t_vec4 *vec);
void					render_set_pixel(t_ftg_ctx *ctx, int x, int y, t_color *color);
void					render_set_zindex(t_ftg_ctx *ctx, int x, int y, double z);
double					render_get_zindex(t_ftg_ctx *ctx, int x, int y);
void					render_render_vertex(t_ftg_ctx *ctx, t_vec4 *vec);
void					render_render_line(t_ftg_ctx *ctx, t_vec4 *v1, t_vec4 *v2);
void					render_render_triangle(t_ftg_ctx *ctx, t_triangle *triangle);
void					camera_watch_vec4(t_camera *camera, t_vec4 *vec);
void					camera_set_position(t_camera *camera, double x, double y, double z);
void					camera_set_rotation(t_camera *camera, double x, double y, double z);
void					camera_set_projection(t_camera *camera, t_mat4 *mat);
long					epoch_millis();

struct					s_triangle_edge
{
	t_color				c1;
	double				x1;
	double				y1;
	double				z1;
	t_color				c2;
	double				x2;
	double				y2;
	double				z2;
};

struct					s_triangle_span
{
	t_color				c1;
	double				x1;
	double				z1;
	t_color				c2;
	double				x2;
	double				z2;
};

struct					s_triangle
{
	t_vec4				v1;
	t_vec4				v2;
	t_vec4				v3;
};

struct					s_camera
{
	t_mat4				projection;
	t_mat4				position;
	t_mat4				rotation;
	t_mat4				view;
	t_vec4				origin;
	int					width;
	int					height;
};

struct					s_env
{
	GLFWwindow			*window;
	char				*window_title;
	int					window_width;
	int					window_height;
	GLuint				texture;
	t_ftg_ctx			ctx;
	t_camera			camera;
};

#endif
