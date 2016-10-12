/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:16:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 16:05:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

t_env	*g_env;

static void	render_render_do(t_env *env)
{
	/*t_vec4 vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.w = 1;
	vec.color.red = 1;
	vec.color.green = 1;
	vec.color.blue = 0;
	camera_watch_vec4(&env->camera, &vec);
	vec.x = vec.x / (env->render.width / 2) - 1;
	vec.y = vec.y / (env->render.height / 2) - 1;
	render_render_vertex(&env->render, &vec);*/
	t_vec4 orgo;
	t_vec4 orgx;
	t_vec4 orgy;
	t_vec4 orgz;

	orgo.x = 0;
	orgo.y = 0;
	orgo.z = 0;
	orgo.w = 1;
	orgo.color.red = 1;
	orgo.color.green = 1;
	orgo.color.blue = 1;
	camera_watch_vec4(&env->camera, &orgo);
	orgo.x = orgo.x / (env->render.width / 2) - 1;
	orgo.y = orgo.y / (env->render.height / 2) - 1;
	orgx.x = 1;
	orgx.y = 0;
	orgx.z = 0;
	orgx.w = 1;
	orgx.color.red = 1;
	orgx.color.green = 0;
	orgx.color.blue = 0;
	camera_watch_vec4(&env->camera, &orgx);
	orgx.x = orgx.x / (env->render.width / 2) - 1;
	orgx.y = orgx.y / (env->render.height / 2) - 1;
	orgy.x = 0;
	orgy.y = 1;
	orgy.z = 0;
	orgy.w = 1;
	orgy.color.red = 0;
	orgy.color.green = 1;
	orgy.color.blue = 0;
	camera_watch_vec4(&env->camera, &orgy);
	orgy.x = orgy.x / (env->render.width / 2) - 1;
	orgy.y = orgy.y / (env->render.height / 2) - 1;
	orgz.x = 0;
	orgz.y = 0;
	orgz.z = 1;
	orgz.w = 1;
	orgz.color.red = 0;
	orgz.color.green = 0;
	orgz.color.blue = 1;
	camera_watch_vec4(&env->camera, &orgz);
	orgz.x = orgz.x / (env->render.width / 2) - 1;
	orgz.y = orgz.y / (env->render.height / 2) - 1;
	render_render_line(&env->render, &orgo, &orgx);
	render_render_line(&env->render, &orgo, &orgy);
	render_render_line(&env->render, &orgo, &orgz);
}

void		render_render(t_render *render)
{
	if (render->texture)
		glDeleteTextures(1, &render->texture);
	glGenTextures(1, &render->texture);
	ft_memset(render->colors, 0, render->width * render->height * 3 * sizeof(float));
	render_render_do(g_env);
	glBindTexture(GL_TEXTURE_2D, render->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, render->width, render->height
			, 0, GL_RGB, GL_FLOAT, render->colors);
	glColorPointer(3, GL_FLOAT, 0, render->colors);
}
