/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 18:06:48 by acazuc           ###   ########.fr       */
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

int				main()
{
	t_mat4	proj;
	t_env	env;
	double ranges[2] = {Z_MIN, Z_MAX};

	ftg_ctx_set(&env.ctx);
	ftg_ctx_init(&env.ctx);
	ftg_viewport(1280, 720);
	mat4_init_projection(&proj, 60, 1280. / 720, ranges);
	g_env = &env;
	ft_memset(&env, 0, sizeof(env));
	if (!glfwInit())
		ERROR("Can't init glfw");
	camera_set_position(&env.camera, 0, 0, -10);
	camera_set_rotation(&env.camera, 0, ft_toradians(0), 0);
	camera_set_projection(&env.camera, &proj);
	window_create(&env);
	glGenTextures(1, &g_env->texture);
	glBindTexture(GL_TEXTURE_2D, g_env->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	double i = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_elements(&env);
		glfwSwapBuffers(env.window);
		camera_set_rotation(&env.camera, ft_toradians(i), ft_toradians(i * 2), ft_toradians(i * 3));
		ftg_clear(FTG_DEPTH_BUFFER_BIT | FTG_COLOR_BUFFER_BIT);
		render_render();
		++i;
		glfwPollEvents();
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glfwTerminate();
	return (EXIT_SUCCESS);
}
