/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_vertex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:39:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:28:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_render_vertex(t_ftg_ctx *ctx, t_vec4 *vec)
{
	t_vec4	tmp;

	ft_memcpy(&tmp, vec, sizeof(tmp));
	tmp.x = ctx->width / 2 + tmp.x * ctx->width / 2;
	tmp.y = ctx->height / 2 + tmp.y * ctx->height / 2;
	render_put_pixel(ctx, &tmp);
}
