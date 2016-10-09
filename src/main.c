/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 15:46:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"
#include <stdio.h>

t_env	*g_env = NULL;

static void		draw_elements(t_env *env)
{
	env->render.colors[0] = 1;
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, env->render.colors);
	glVertexPointer(2, GL_INT, 0, env->render.vertex);
	glDrawArrays(GL_POINTS, 0, env->render.width * env->render.height);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

int				main()
{
	t_env	env;

	g_env = &env;
	ft_memset(&env, 0, sizeof(env));
	if (!glfwInit())
		ERROR("Can't init glfw");
	window_create(&env);
	while (!glfwWindowShouldClose(env.window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_elements(&env);
		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	glfwTerminate();
	return (EXIT_SUCCESS);
}
