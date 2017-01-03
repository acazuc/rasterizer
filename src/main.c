/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 17:23:44 by acazuc           ###   ########.fr       */
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

static void key_listener(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	int	*swit;

	if (key == GLFW_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key == GLFW_KEY_LEFT)
		swit = &g_env->key_left_down;
	else if (key == GLFW_KEY_UP)
		swit = &g_env->key_up_down;
	else if (key == GLFW_KEY_RIGHT)
		swit = &g_env->key_right_down;
	else if (key == GLFW_KEY_DOWN)
		swit = &g_env->key_down_down;
	else if (key == GLFW_KEY_W)
		swit = &g_env->key_w_down;
	else if (key == GLFW_KEY_A)
		swit = &g_env->key_a_down;
	else if (key == GLFW_KEY_S)
		swit = &g_env->key_s_down;
	else if (key == GLFW_KEY_D)
		swit = &g_env->key_d_down;
	else if (key == GLFW_KEY_LEFT_SHIFT)
		swit = &g_env->key_lshift_down;
	else if (key == GLFW_KEY_SPACE)
		swit = &g_env->key_space_down;
	else
		return;
	*swit = action != GLFW_RELEASE;
	(void)window;
	(void)key;
	(void)scancode;
	(void)action;
	(void)mods;
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
	glfwSetKeyCallback(env.window, key_listener);
	env.posz = -2;
	double i = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		if (env.key_left_down)
			env.roty += ROT_FAC;
		if (env.key_right_down)
			env.roty -= ROT_FAC;
		if (env.key_up_down)
			env.rotx += ROT_FAC;
		if (env.key_down_down)
			env.rotx -= ROT_FAC;
		if (env.key_w_down)
			env.posz += MOV_FAC;
		if (env.key_a_down)
			env.posx -= MOV_FAC;
		if (env.key_s_down)
			env.posz -= MOV_FAC;
		if (env.key_d_down)
			env.posx += MOV_FAC;
		if (env.key_lshift_down)
			env.posy += MOV_FAC;
		if (env.key_space_down)
			env.posy -= MOV_FAC;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ftg_clear(FTG_DEPTH_BUFFER_BIT | FTG_COLOR_BUFFER_BIT);
		ftg_load_identity();
		ftg_translated(-env.posx, -env.posy, env.posz);
		ftg_rotated(env.rotx, 1, 0, 0);
		ftg_rotated(env.roty, 0, 1, 0);
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
