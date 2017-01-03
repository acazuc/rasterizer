/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_fog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:31:15 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 17:32:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_boolean	pname_is_valid(t_ftg_enum pname)
{
	if (pname == FTG_FOG_MODE || pname == FTG_FOG_DENSITY
		|| pname == FTG_FOG_START || pname == FTG_FOG_END
		|| pname == FTG_FOG_INDEX || pname == FTG_FOG_COLOR)
		return (FTG_TRUE);
	return (FTG_FALSE);
}

void					ftg_fogf(t_ftg_enum pname, t_ftg_float param)
{
	if (pname == FTG_FOG_COLOR)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	ftg_fogfv(pname, &param);
}

void					ftg_fogi(t_ftg_enum pname, t_ftg_int param)
{
	if (pname == FTG_FOG_COLOR)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	ftg_fogiv(pname, &param);
}

void					ftg_fogfv(t_ftg_enum pname, t_ftg_float *param)
{
	if (!pname_is_valid(pname))
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (pname == FTG_FOG_DENSITY)
		ftg_fog_density(param, FTG_FLOAT);
	else if (pname == FTG_FOG_START)
		ftg_fog_start(param, FTG_FLOAT);
	else if (pname == FTG_FOG_END)
		ftg_fog_end(param, FTG_FLOAT);
	else if (pname == FTG_FOG_INDEX)
		ftg_fog_index(param, FTG_FLOAT);
	else if (pname == FTG_FOG_MODE)
		ftg_fog_mode(param, FTG_FLOAT);
	else if (pname == FTG_FOG_COLOR)
		ftg_fog_color(param, FTG_FLOAT);
}

void					ftg_fogiv(t_ftg_enum pname, t_ftg_int *param)
{
	if (!pname_is_valid(pname))
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (pname == FTG_FOG_DENSITY)
		ftg_fog_density(param, FTG_INT);
	else if (pname == FTG_FOG_START)
		ftg_fog_start(param, FTG_INT);
	else if (pname == FTG_FOG_END)
		ftg_fog_end(param, FTG_INT);
	else if (pname == FTG_FOG_INDEX)
		ftg_fog_index(param, FTG_INT);
	else if (pname == FTG_FOG_MODE)
		ftg_fog_mode(param, FTG_INT);
	else if (pname == FTG_FOG_COLOR)
		ftg_fog_color(param, FTG_INT);
}
