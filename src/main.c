/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 16:52:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"
#include <stdio.h>

t_env	*g_env = NULL;

static void		draw_elements(t_env *env)
{
	int		coords[4 * 2];
	int		vertex[4 * 2];

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, env->ctx.width, env->ctx.height, 0, GL_RGBA, GL_FLOAT, env->ctx.color_buffer);
	ft_memset(coords, 0, sizeof(coords));
	coords[2] = 1;
	coords[4] = 1;
	coords[5] = 1;
	coords[7] = 1;
	ft_memset(vertex, 0, sizeof(vertex));
	vertex[2] = env->ctx.width;
	vertex[4] = env->ctx.width;
	vertex[5] = env->ctx.height;
	vertex[7] = env->ctx.height;
	glVertexPointer(2, GL_INT, 0, vertex);
	glTexCoordPointer(2, GL_INT, 0, coords);
	glDrawArrays(GL_QUADS, 0, 4);
}

static void cursor_listener(GLFWwindow *window, double x, double y)
{
	g_env->delta_x = x - g_env->mouse_x;
	g_env->delta_y = y - g_env->mouse_y;
	g_env->mouse_x = x;
	g_env->mouse_y = y;
	(void)window;
}

static void move()
{
	g_env->roty -= g_env->delta_x * ROT_FAC;
	g_env->rotx -= g_env->delta_y * ROT_FAC;
	g_env->delta_x = 0;
	g_env->delta_y = 0;
	g_env->roty = fmod(g_env->roty, 360);
	if (g_env->rotx > 90)
		g_env->rotx = 90;
	else if (g_env->rotx < -90)
		g_env->rotx = -90;
	int left = glfwGetKey(g_env->window, GLFW_KEY_A) == GLFW_PRESS;
	int right = glfwGetKey(g_env->window, GLFW_KEY_D) == GLFW_PRESS;
	int front = glfwGetKey(g_env->window, GLFW_KEY_W) == GLFW_PRESS;
	int back = glfwGetKey(g_env->window, GLFW_KEY_S) == GLFW_PRESS;
	if (left && right)
	{
		left = 0;
		right = 0;
	}
	if (front && back)
	{
		front = 0;
		back = 0;
	}
	if (!left && !right && !front && !back)
		return;
	double angle = g_env->roty;
	if (back)
	{
		if (left)
			angle += 135;
		else if (right)
			angle += 45;
		else
			angle += 90;
	}
	else if (front)
	{
		if (left)
			angle += -135;
		else if (right)
			angle += -45;
		else
			angle += -90;
	}
	else if (left)
		angle += 180;
	else if (right)
		angle += 0;
	g_env->posx += cos(TO_RADIANS(angle)) * MOV_FAC;
	g_env->posz += sin(TO_RADIANS(angle)) * MOV_FAC;
}

int				main()
{
	t_env	env;

	g_env = &env;
	ft_memset(&env, 0, sizeof(env));
	ftg_ctx_set(&env.ctx);
	ftg_ctx_init(&env.ctx);
	ftg_viewport(1280, 720);
	ftg_enable(FTG_DEPTH_TEST);
	if (!glfwInit())
		ERROR("Can't init glfw");
	window_create(&env);
	glGenTextures(1, &g_env->texture);
	glBindTexture(GL_TEXTURE_2D, g_env->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	ftg_enable_client_state(FTG_VERTEX_ARRAY);
	ftg_enable_client_state(FTG_COLOR_ARRAY);
	float colors[24] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1};
	double vertex[24] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1};
	float colors2[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	double vertex2[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	float colors3[12] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1};
	double vertex3[12] = {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0};
	ftg_matrix_mode(FTG_PROJECTION);
	ftg_perspective(120, 1280. / 720, Z_MIN, Z_MAX);
	ftg_matrix_mode(FTG_MODELVIEW);
	glfwSetCursorPosCallback(g_env->window, cursor_listener);
	glfwSetInputMode(g_env->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	env.posz = -2;
	double i = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		move();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ftg_clear(FTG_DEPTH_BUFFER_BIT | FTG_COLOR_BUFFER_BIT);
		ftg_load_identity();
		ftg_rotated(env.rotx, 1, 0, 0);
		ftg_rotated(-env.roty, 0, 1, 0);
		ftg_translated(-env.posx, -env.posy, env.posz);
		ftg_scaled(1, 1, 1);
		ftg_color_pointer(3, FTG_FLOAT, 0, colors);
		ftg_vertex_pointer(3, FTG_DOUBLE, 0, vertex);
		ftg_draw_arrays(FTG_LINES, 0, 3);
		ftg_color_pointer(3, FTG_FLOAT, 0, colors2);
		ftg_vertex_pointer(3, FTG_DOUBLE, 0, vertex2);
		//ftg_draw_arrays(FTG_TRIANGLES, 0, 1);
		ftg_color_pointer(3, FTG_FLOAT, 0, colors3);
		ftg_vertex_pointer(3, FTG_DOUBLE, 0, vertex3);
		//ftg_draw_arrays(FTG_QUADS, 0, 1);
		draw_elements(&env);
		glfwSwapBuffers(env.window);
		glfwPollEvents();
		++i;
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glfwTerminate();
	return (EXIT_SUCCESS);
}
