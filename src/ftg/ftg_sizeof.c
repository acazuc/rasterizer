/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_sizeof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:09:32 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:14:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

t_ftg_sizei	ftg_sizeof(t_ftg_enum type)
{
	if (type == FTG_BOOLEAN)
		return (sizeof(t_ftg_boolean));
	else if (type == FTG_BYTE)
		return (sizeof(t_ftg_byte));
	else if (type == FTG_UNSIGNED_BYTE)
		return (sizeof(t_ftg_ubyte));
	else if (type == FTG_SHORT)
		return (sizeof(t_ftg_short));
	else if (type == FTG_UNSIGNED_SHORT)
		return (sizeof(t_ftg_ushort));
	else if (type == FTG_INT)
		return (sizeof(t_ftg_int));
	else if (type == FTG_UNSIGNED_INT)
		return (sizeof(t_ftg_uint));
	else if (type == FTG_FLOAT)
		return (sizeof(t_ftg_float));
	else if (type == FTG_CLAMPF)
		return (sizeof(t_ftg_clampf));
	else if (type == FTG_DOUBLE)
		return (sizeof(t_ftg_double));
	else if (type == FTG_CLAMPD)
		return (sizeof(t_ftg_clampd));
	return (0);
}
