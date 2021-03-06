/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_minbsf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:33:16 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 17:33:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_byte		ftg_minb(t_ftg_byte b1, t_ftg_byte b2)
{
	return (b1 < b2 ? b1 : b2);
}

t_ftg_ubyte		ftg_minub(t_ftg_ubyte b1, t_ftg_ubyte b2)
{
	return (b1 < b2 ? b1 : b2);
}

t_ftg_short		ftg_mins(t_ftg_short s1, t_ftg_short s2)
{
	return (s1 < s2 ? s1 : s2);
}

t_ftg_ushort	ftg_minus(t_ftg_ushort s1, t_ftg_ushort s2)
{
	return (s1 < s2 ? s1 : s2);
}

t_ftg_float		ftg_minf(t_ftg_float f1, t_ftg_float f2)
{
	return (f1 < f2 ? f1 : f2);
}
