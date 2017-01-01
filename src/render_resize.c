/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:19:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 18:00:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void		render_resize(t_ftg_ctx *ctx, int width, int height)
{
	ftg_viewport(width, height);
	render_render(ctx);
}
