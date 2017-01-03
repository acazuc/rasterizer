/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_minild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:33:18 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 17:33:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_int		ftg_mini(t_ftg_int i1, t_ftg_int i2)
{
	return (i1 < i2 ? i1 : i2);
}

t_ftg_uint		ftg_minui(t_ftg_uint i1, t_ftg_uint i2)
{
	return (i1 < i2 ? i1 : i2);
}

t_ftg_long		ftg_minl(t_ftg_long l1, t_ftg_long l2)
{
	return (l1 < l2 ? l1 : l2);
}

t_ftg_ulong		ftg_minul(t_ftg_ulong l1, t_ftg_ulong l2)
{
	return (l1 < l2 ? l1 : l2);
}

t_ftg_double	ftg_mind(t_ftg_double d1, t_ftg_double d2)
{
	return (d1 < d2 ? d1 : d2);
}
