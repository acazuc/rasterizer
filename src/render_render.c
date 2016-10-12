/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:16:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 13:25:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

t_env	*g_env;

static void	render_render_do(t_env *env)
{
	t_vec4 vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.color.red = 1;
	vec.color.green = 0;
	vec.color.blue = 0;
	camera_watch_vec4(&env->camera, &vec);
	vec.x = vec.x / (env->render.width / 2) - 1;
	vec.y = vec.y / (env->render.height / 2) - 1;
	render_render_vertex(&env->render, &vec);
}

void		render_render(t_render *render)
{
	if (render->texture)
		glDeleteTextures(1, &render->texture);
	glGenTextures(1, &render->texture);
	ft_memset(render->colors, 0, render->width * render->height);
	render_render_do(g_env);
	glBindTexture(GL_TEXTURE_2D, render->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, render->width, render->height
			, 0, GL_RGB, GL_FLOAT, render->colors);
	glColorPointer(3, GL_FLOAT, 0, render->colors);
}
