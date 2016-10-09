/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_listener_resize.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:28:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 13:39:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

t_env	*g_env;

void	window_listener_resize(GLFWwindow *window, int width, int height)
{
	g_env->window_width = width;
	g_env->window_height = height;
	render_resize(&g_env->render, width, height);
	g_env->camera.width = width;
	g_env->camera.height = height;
	window_update_context(g_env);
	(void)window;
}
