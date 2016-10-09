/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:16:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 17:02:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_render(t_render *render)
{
	if (render->texture)
		glDeleteTextures(1, &render->texture);
	glGenTextures(1, &render->texture);
	glBindTexture(GL_TEXTURE_2D, render->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, render->width, render->height
			, 0, GL_RGB, GL_FLOAT, render->colors);
	glColorPointer(3, GL_FLOAT, 0, render->colors);
}
