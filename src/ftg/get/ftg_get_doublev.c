/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_get_doublev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:55:58 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:30:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	ftg_get_doublev_convert(t_ftg_double *params, void *data
		, t_ftg_enum format, t_ftg_uint length)
{
	t_ftg_uint	i;

	i = 0;
	while (i < length)
	{
		if (format == FTG_BOOLEAN)
			params[i] = ((t_ftg_boolean*)data)[i];
		if (format == FTG_BYTE)
			params[i] = ((t_ftg_byte*)data)[i];
		else if (format == FTG_UNSIGNED_BYTE)
			params[i] = ((t_ftg_ubyte*)data)[i];
		else if (format == FTG_SHORT)
			params[i] = ((t_ftg_short*)data)[i];
		else if (format == FTG_UNSIGNED_SHORT)
			params[i] = ((t_ftg_ushort*)data)[i];
		else if (format == FTG_INT)
			params[i] = ((t_ftg_int*)data)[i];
		else if (format == FTG_UNSIGNED_INT)
			params[i] = ((t_ftg_uint*)data)[i];
		else if (format == FTG_FLOAT)
			params[i] = ((t_ftg_float*)data)[i];
		else if (format == FTG_CLAMPF)
			params[i] = ((t_ftg_clampf*)data)[i];
		else if (format == FTG_CLAMPD)
			params[i] = ((t_ftg_clampd*)data)[i];
		++i;
	}
}

void		ftg_get_doublev(t_ftg_enum pname, t_ftg_double *params)
{
	void		*data;
	t_ftg_enum	format;
	t_ftg_uint	length;

	if (!ftg_get(pname, &data, &format, &length))
		return ;
	if (format == FTG_DOUBLE)
	{
		ft_memcpy(params, data, length * sizeof(*params));
		return ;
	}
	ftg_get_doublev_convert(params, data, format, length);
}
