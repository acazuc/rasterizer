/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_identity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:33:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 12:09:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_identity(t_mat4 *mat)
{
	mat4_clear(mat);
	mat->value[0] = 1;
	mat->value[5] = 1;
	mat->value[10] = 1;
	mat->value[15] = 1;
}
