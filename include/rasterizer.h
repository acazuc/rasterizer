/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:48:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 12:09:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTERIZER_H
# define RASTERIZER_H

# include "../libft/include/libft.h"
# include "../glfw/include/GLFW/glfw3.h"

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))

typedef struct s_mat4	t_mat4;
typedef struct s_vec4	t_vec4;
typedef struct s_color	t_color;
typedef struct s_camera	t_camera;
typedef struct s_render	t_render;
typedef struct s_env	t_env;

void					error_quit(char *str, char *file, int line);
void					window_create(t_env *env);
void					window_update_context(t_env *env);
void					window_listener_resize(GLFWwindow *window, int width, int height);
void					mat4_clear(t_mat4 *mat);
void					mat4_init_identity(t_mat4 *mat);
void					mat4_init_translation(t_mat4 *mat, double x, double y, double z);
void					mat4_init_rotation_x(t_mat4 *mat, double angle);
void					mat4_init_rotation_y(t_mat4 *mat, double angle);
void					mat4_init_rotation_z(t_mat4 *mat, double angle);
t_mat4					mat4_mult(t_mat4 *m1, t_mat4 *m2);

struct					s_color
{
	double				red;
	double				green;
	double				blue;
	double				alpha;
};

struct					s_vec4
{
	t_color				color;
	double				x;
	double				y;
	double				z;
	double				w;
};

struct					s_mat4
{
	double				value[4][4];
};

struct					s_camera
{
	t_mat4				projection;
	t_mat4				trans_rot;
	t_vec4				origin;
};

struct					s_render
{
	double				**z_index;
	double				*colors;
	double				*vertex;
};

struct					s_env
{
	GLFWwindow			*window;
	char				*window_title;
	int					window_width;
	int					window_height;
	t_render			render;
};

#endif
