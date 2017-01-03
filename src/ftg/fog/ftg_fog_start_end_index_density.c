/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_fog_start_end_index_density.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:32:14 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:37:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static t_ftg_double	val_convert_to_double(void *data, t_ftg_enum type)
{
	if (type == FTG_FLOAT)
	{
		return (((t_ftg_float*)data)[0]);
	}
	else if (type == FTG_INT)
	{
		return (((t_ftg_int*)data)[0]);
	}
	return (0);
}

void				ftg_fog_start(void *data, t_ftg_enum type)
{
	g_ctx->fog_start = val_convert_to_double(data, type);
}

void				ftg_fog_end(void *data, t_ftg_enum type)
{
	g_ctx->fog_end = val_convert_to_double(data, type);
}

void				ftg_fog_index(void *data, t_ftg_enum type)
{
	g_ctx->fog_index = val_convert_to_double(data, type);
}

void				ftg_fog_density(void *data, t_ftg_enum type)
{
	double	density;

	density = val_convert_to_double(data, type);
	if (density < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	g_ctx->fog_density = density;
}
