/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 11:30:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

t_env	*g_env = NULL;

int		main()
{
	t_env	env;

	g_env=  &env;
	if (!glfwInit())
		ERROR("Can't init glfw");
	window_create(&env);
	while (!glfwWindowShouldClose(env.window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	glfwTerminate();
	return (EXIT_SUCCESS);
}
