/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_blend_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:27:32 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:23:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_blend_func(t_ftg_enum s_factor, t_ftg_enum d_factor)
{
	ftg_blend_func_separate(s_factor, d_factor, s_factor, d_factor);
}
