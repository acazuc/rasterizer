/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:48:34 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:18:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTERIZER_H
# define RASTERIZER_H

# include "../libft/include/libft.h"
# include "../glfw/include/GLFW/glfw3.h"
# include "libftg.h"
# include "mat4.h"
# include <sys/time.h>
# include <stdio.h>
# include <math.h>

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))
# define MAX(x, y) ((x) < (y) ? (y) : (x))
# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define ABS(x) ((x) < 0 ? (-(x)) : x)

# define TO_RADIANS(x) (x / 360. * M_PI)

# define Z_MIN 0.001
# define Z_MAX 10

# define ROT_FAC 0.001
# define MOV_FAC 0.1

typedef struct s_env			t_env;

void					error_quit(char *str, char *file, int line);
void					window_create(t_env *env);
void					window_update_context(t_env *env);
void					window_listener_resize(GLFWwindow *window, int width
		, int height);
long					epoch_millis();

struct					s_env
{
	GLFWwindow			*window;
	char				*window_title;
	int					window_width;
	int					window_height;
	GLuint				texture;
	t_ftg_ctx			ctx;
	long				mouse_x;
	long				mouse_y;
	long				delta_x;
	long				delta_y;
	double				posx;
	double				posy;
	double				posz;
	double				rotx;
	double				roty;
	double				rotz;
};

#endif
