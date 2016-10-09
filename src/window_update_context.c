/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_update_context.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:26:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 11:27:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	window_update_context(t_env *env)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glViewport(0, 0, env->window_width, env->window_height);
	glMatrixMode(GL_MODELVIEW);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, env->window_width, env->window_height, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0, 0, 0, 1);
}
