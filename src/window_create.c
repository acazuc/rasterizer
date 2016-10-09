/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:20:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 15:17:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	window_create(t_env *env)
{
	env->window_width = 1280;
	env->window_height = 720;
	env->window_title = "acazuc's rasterizer";
	if (!(env->window = glfwCreateWindow(env->window_width, env->window_height
					, env->window_title, NULL, NULL)))
		ERROR("Window: can't create window");
	glfwSwapInterval(1);
	glfwMakeContextCurrent(env->window);
	glfwSetFramebufferSizeCallback(env->window, window_listener_resize);
	window_listener_resize(env->window, env->window_width, env->window_height);
	window_update_context(env);
}
