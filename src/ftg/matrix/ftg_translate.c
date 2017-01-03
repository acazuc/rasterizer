/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:55:25 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 18:55:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_translated(t_ftg_double x, t_ftg_double y, t_ftg_double z)
{
	t_mat4	translate;

	mat4_init_translation(&translate, x, y, z);
	ftg_mult_matrixd(translate.value);
}

void	ftg_translatef(t_ftg_float x, t_ftg_float y, t_ftg_float z)
{
	ftg_translated(x, y, z);
}
