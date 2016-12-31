/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:16:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 18:37:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

t_env	*g_env;

static void	render_render_do(t_env *env)
{
	t_triangle triangle;
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
	orgo.color.alpha = 1;
	camera_watch_vec4(&env->camera, &orgo);
	orgx.x = 1;
	orgx.y = 0;
	orgx.z = 0;
	orgx.w = 1;
	orgx.color.red = 1;
	orgx.color.green = 0;
	orgx.color.blue = 0;
	orgx.color.alpha = 1;
	camera_watch_vec4(&env->camera, &orgx);
	orgy.x = 0;
	orgy.y = 1;
	orgy.z = 0;
	orgy.w = 1;
	orgy.color.red = 0;
	orgy.color.green = 1;
	orgy.color.blue = 0;
	orgy.color.alpha = 1;
	camera_watch_vec4(&env->camera, &orgy);
	orgz.x = 0;
	orgz.y = 0;
	orgz.z = 1;
	orgz.w = 1;
	orgz.color.red = 0;
	orgz.color.green = 0;
	orgz.color.blue = 1;
	orgz.color.alpha = 1;
	camera_watch_vec4(&env->camera, &orgz);
	render_render_line(&env->ctx, &orgo, &orgx);
	render_render_line(&env->ctx, &orgo, &orgy);
	render_render_line(&env->ctx, &orgo, &orgz);
	triangle.v1 = orgx;
	triangle.v2 = orgy;
	triangle.v3 = orgz;
	render_render_triangle(&env->ctx, &triangle);
}

void		render_render(t_ftg_ctx *ctx)
{
	//if (!ctx->texture)
//		glGenTextures(1, &ctx->texture);
	ft_memset(ctx->colors, 0, ctx->width * ctx->height * 3 * sizeof(*ctx->colors));
	ft_memset(ctx->z_index, 0, ctx->width * ctx->height * sizeof(*ctx->z_index));
	render_render_do(g_env);
	//glBindTexture(GL_TEXTURE_2D, ctx->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ctx->width, ctx->height
			, 0, GL_RGB, GL_FLOAT, ctx->colors);
}
